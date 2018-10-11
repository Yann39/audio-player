# Audio player

The purpose of this project was to create a **Windows MFC** (**M**icrosoft **F**oundation **C**lass library) application for playing **MP3 audio files**.

This program was part of a school project and was created in **December 2007**.

It was originally created with **Microsoft Visual Studio 2005**.

## Usage

Just run the _LecteurAudio.exe_ file from the _Release_ directory, then play with the UI :

![Main interface](doc/main_interface.png?raw=true "Main interface")

Note : you must have the **FMod Ex** library (_fmodex.dll_) in the same folder.

## Description

### FMod Ex library

The **FMOD** library basically allows reading audio files, it is a cross-platform sound management library available for many languages.
It is free for personal use.

The **FMOD Ex** version of the library has been used (FMOD 3 Programmers API Version 3.75), which makes it very easy to write audio applications for most of the .NET platform languages, namely C, C ++, C #, Delphi and Visual Basic.

FMOD (v3.75) supports no less than 22 music formats:
- AIFF : Audio Interchange File Format
- ASF : Advanced Streaming Format, includes support for audio tracks in video streams
- ASX : Playlist format exploitable thanks to the FMOD Ex tag API
- DLS : DownLoadable Sound format for MIDI Sounds
- FLAC : Lossless compression codec
- FSB : FMOD Sample Bank format generated with FSBank and FMOD designer tools
- IT : Sequential format Impulse tracker. Does not require the presence of DirectX to be played.
- M3U : Playlist format exploitable thanks to the FMOD Ex tag API
- MID : MIDI format using the operating system or DLS patches
- MOD : Sequential format Protracker / Fasttracker and other sequential formats
- MP2 : MPEG I / II Layer 2
- MP3 : MPEG I / II Layer 3, with VBR support
- OGG : Format Ogg Vorbis
- PLS : Playlist format exploitable thanks to the FMOD Ex tag API
- RAW : Raw Format. The user can specify the number of channels, format etc.
- S3M : ScreamTracker Sequential Format 3
- VAG : Format specific to PS2 / PSP
- WAV : Microsoft Wave files, including compressed Wave files.
- WAX : Playlist format exploitable thanks to the FMOD Ex tag API
- WMA : Windows Media Audio Format
- XM : FastTracker 2 Sequential Format
- XMA : Format specific to Xbox 360

FMOD Ex is available for download from the official FMOD website at the following address: http://www.fmod.org

### Program

TODO

## Licence

WTFPL license : http://www.wtfpl.net/

But a mention is always appreciated :)