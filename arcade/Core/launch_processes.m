function procs = launch_processes(cfg)


% defaults
if ~exist('cfg', 'var'); cfg = ArcadeConfig; end

procs = {};
readyEvents = {};
% launch other processes
for iExe = 1:length(cfg.OtherExecutables)
    cmd = cfg.OtherExecutables{iExe};
    logmessage(sprintf('Starting %s', cmd))
    procs{end+1} =  processManager('id', cmd, 'command',  cmd);
end

% launch control screen process
if ~strcmp(cfg.ControlScreen, 'None') && ~isempty(cfg.ControlScreen)
    logmessage(sprintf('Starting %s', cfg.ControlScreen))
    
    controlScreenExePath = fullfile(arcaderoot, 'arcade', ...
        'ControlScreen', cfg.ControlScreen);
    procs{end+1} = processManager('id', 'ControlScreen', ...
        'command',  controlScreenExePath, ...
        'workingDir', fullfile(arcaderoot, 'arcade', 'ControlScreen'), ...
        'printStdout', false, 'printStderr', false);
    controlScreenDoneEvent = IPCEvent('ControlScreenDone');
    readyEvents{end+1} = controlScreenDoneEvent.name;
end

% launch EyeServer process
if ~strcmp(cfg.EyeServer, 'None') && ~isempty(cfg.EyeServer)
    logmessage('Starting EyeServer')
    eyeServerExePath = fullfile(arcaderoot, 'arcade', ...
        'EyeServer', cfg.EyeServer);
    procs{end+1} = processManager('id', 'EyeServer', ...
        'command', eyeServerExePath);
    readyEvents{end+1} = EyeServer.doneEventName;
end

% launch DaqServer process
if ~strcmp(cfg.DaqServer, 'None') && ~isempty(cfg.DaqServer)
    logmessage('Starting DaqServer')
    daqServerExePath = fullfile(arcaderoot, 'arcade', ...
        'DaqServer', cfg.DaqServer);
    procs{end+1} = processManager('id', 'DaqServer', ...
        'command', daqServerExePath);
    readyEvents{end+1} = DaqServer.doneEventName;
end


% launch StimServer process
if ~strcmp(cfg.StimServer, 'None') && ~isempty(cfg.StimServer)
    logmessage('Starting StimServer')
    stimServerExePath = fullfile(arcaderoot, 'arcade', ...
        'StimServer', cfg.StimServer);
    procs{end+1} = processManager('id', 'StimServer', ...
        'command',  stimServerExePath);
    readyEvents{end+1} = StimServer.doneEventName;
end

logmessage('Waiting for processes to start')
pause(0.5)
MultipleEvents.Init(readyEvents)
result = MultipleEvents.WaitFor(readyEvents, 1, 20000);
assert(result == 1, 'Not all processes could be started within 5 s')

% connect to StimServer
if ~strcmp(cfg.StimServer, 'None') && ~isempty(cfg.StimServer)
    logmessage('Connect to StimServer')
    StimServer.Connect();
end

% connect to DaqServer
if ~strcmp(cfg.DaqServer, 'None') && ~isempty(cfg.DaqServer)
    logmessage('Connect to DaqServer')
    DaqServer.Connect();
end

% connect to EyeServer
if ~strcmp(cfg.EyeServer, 'None') && ~isempty(cfg.EyeServer)
    logmessage('Connect to EyeServer')
    EyeServer.Connect();
    EyeServer.Start()
end

% connect to ControlScreen
if ~strcmp(cfg.ControlScreen, 'None')
    logmessage('Connect to ControlScreen')
    SGLTrialDataPipe.Open()
    IPCEvent.set_event('ControlScreenDone')
end

