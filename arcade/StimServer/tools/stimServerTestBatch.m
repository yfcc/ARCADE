%% launch and connect to StimServer
run('C:\Toolbox\ARCADE\arcade\add_arcade_to_path.m')
try 
    StimServer.Disconnect()
catch
end
cfg = ArcadeConfig;
cfg.ControlScreen = [];
cfg.DaqServer = [];
cfg.StimServer = 'StimServer.exe';
p = launch_processes(cfg);