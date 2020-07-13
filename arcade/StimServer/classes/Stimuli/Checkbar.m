classdef Checkbar < PixelShader
    % Checkbar < PixelShader < Stimulus - Moving 2x2 checker bar
    properties ( Access = public, Transient = true )
        color1 = [255 255 255 255]; % [r g b alpha]/[r g b]
        color2 = [0 0 0 255]; % [r g b alpha]/[r g b]
        width  = 20;    % width of of checker bar
        height = 100;   % height of checker bar
        angle  = 0;     % as moving bar 
        smoothing = 1;  % width of anti-aliasing window in p
        temporalFrequency = 5; % cycles / s
    end
    
    properties ( Access = private, Transient = true )
        frameRate = [];
    end
    
    methods
        function obj = Checkbar()
            % file for this stimulus
            checkbarfxFile = 'Checkbar.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')), checkbarfxFile);
            obj = obj@PixelShader(filename);
            
            % set defaults
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;  
            obj.width  = obj.width;
            obj.height = obj.height;
            obj.angle  = obj.angle;
            obj.smoothing = obj.smoothing;
            obj.frameRate = StimServer.GetFrameRate();
            obj.temporalFrequency = obj.temporalFrequency;
        end
        
        function set.color1(obj, rgbw)
            if numel(rgbw) == 3
                rgbw = [rgbw 255];
            end
            obj.setColor(1, rgbw)
            obj.color1 = rgbw;
        end
        
        function set.color2(obj, rgbw)
            if numel(rgbw) == 3
                rgbw = [rgbw 255];
            end
            obj.setColor(2, rgbw)
            obj.color2 = rgbw;
        end
        
        function set.width(obj, width)
            obj.setParameter(1,width)
            obj.shaderWidth = 4000;
            obj.width = width;
        end
        
        function set.height(obj,height)
            obj.setParameter(2,height);
            obj.shaderHeight = 4000;
            obj.height = height;
        end
        
        function set.angle(obj, angle)
            obj.setParameter(3, angle)
            obj.angle = angle;
        end
        
        function set.smoothing(obj, smoothing)
            obj.setParameter(6, smoothing)
            obj.smoothing = smoothing;
        end
        
        function set.temporalFrequency(obj, cyclesPerSecond)
            obj.animationIncrement = cyclesPerSecond/obj.frameRate;
            obj.temporalFrequency = cyclesPerSecond;
        end               
    end    
end