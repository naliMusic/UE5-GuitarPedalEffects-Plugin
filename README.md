# [UE5 Plugin] Guitar Pedal Effects
### *Guitar Effects - An Unreal Engine 5 plugin*
> There are 2 versions of the plugin:
> * (1) a custom Metasound node (MetasoundNodes folder)
> * (2) a source effect that can be used in preset chain (SourceEffects folder)  

[[Setup](README.md#computer-Setup)] [[Tremolo](README.md#guitar-tremolo)]  [[Adding-more...](README.md#guitar-More...)]

## :gear: Setup
Follow the link [Source Effect](https://forums.unrealengine.com/t/making-a-ue-plugin-for-audio-from-scratch/152606) or [Metasound Node](https://dev.epicgames.com/community/learning/tutorials/KJWk/writing-a-pitch-shift-metasound-node) to create the plugin project.

Some notes regarding adding dependencies:

```
1. Make sure you add UE Metasound dependencies in your *.Build.cs*
2. Add Metasound Plugins in *.uplugin* file
3. Generate project file to refresh
```
  

## :guitar: Tremolo
This is a simple version of Tremolo effect using sine waveform as the LFO.
The Tremolo effect has 2 parameters Rate, and Depth. Here is the UI:  

![MetasoundTremolo UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/mts_tremolo.jpg)
![SoureEffect UI](https://github.com/naliMusic/UE5-GuitarPedalEffects-Plugin/blob/main/Img/se_tremolo.jpg)

- [x] RATE: LFO frequency (Hz) range from 0.1 to 10.0 (default is 2.0Hz)
- [x] DEPTH: Intensity of the Tremolo (0% - 100%) range from 0.0 to 1.0 (default is 0.5 or 50%)


## :guitar: More...