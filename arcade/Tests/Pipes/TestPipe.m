classdef TestPipe < MSMessagePipe
    properties
        hPipe = [];
        pipeBuffer = [14 14]; % [out, in] relative to server
        pipeName   = '\\.\pipe\testPipe';
    end
    
end