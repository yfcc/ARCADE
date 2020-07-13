function stim = CalibrationStimulusF()
fixDotColor  = [255 0 0 255];
stim = cell(1,2);
stim{1} = Gabor;
stim{1}.position = [0,0]; 
stim{1}.color1 = [0 0 0 100]; 
stim{1}.color2 = [0 0 0 100];
stim{1}.maskWidth = 2;  
stim{1}.maskHeight = 2;  
stim{1}.visible = 1;

stim{2} = Gabor;
stim{2}.position = [0,0]; 
stim{2}.color1 = fixDotColor; 
stim{2}.color2 = fixDotColor;
stim{2}.maskWidth = 1;  
stim{2}.maskHeight = 1;  
stim{2}.visible = 1;