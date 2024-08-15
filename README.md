# [UE5 Plugin] Guitar Pedal Effects
### *Guitar Effects - An Unreal Engine 5 plugin*
> There are 2 versions of the plugin:
> * (1) a custom Metasound node (MetasoundNodes folder)
> * (2) a source effect that can be used in preset chain (SourceEffects folder)  

[[Setup](README.md#gear-Setup)] [[Tremolo](README.md#guitar-tremolo)] [[Vibrato](README.md#guitar-vibrato)] [[Adding-more-effects...](README.md#guitar-more-effects)]
![Plugin UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/plugin.jpg)

## :gear: Setup
Clone the repo into your project or engine plugin folder.
  

## :guitar: Tremolo
Tremolo is an amplitude modulation effect. This is a simple implementation of Tremolo effect using sine waveform as the LFO.
The Tremolo effect has 2 parameters Rate, and Depth.
- [x] RATE: LFO frequency (Hz) range from 0.1 to 10.0 (default is 2.0Hz)
- [x] DEPTH: Intensity of the Tremolo (0% - 100%) range from 0.0 to 1.0 (default is 0.5 or 50%)

Here is the UI:  
![MetasoundTremolo UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/mts_tremolo.jpg) ![SoureEffect UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/sceff_tremolo.jpg)

## :guitar: Vibrato
Vibrato is a modulated delay effect. This is a simple implementation of Vibrato effect using sine waveform as the LFO and linear interpolation.
The Vibrato effect has 2 parameters Rate, and Width.
- [x] RATE: LFO frequency (Hz) range from 0.1 to 10.0 (default is 2.0Hz)
- [x] WIDTH: Delay length (ms) range from 1.0 to 50.0 (default is 10.0ms)

Here is the UI:  
![MetasoundTremolo UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/mts_vibrato.jpg) ![SoureEffect UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/sceff_vibrato.jpg)

## :guitar: More-effects
