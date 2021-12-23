# VideoPlayer

![alt text](https://github.com/ferrellsl/VideoPlayer/blob/main/screenshot.png?raw=true)

The installer for version 2.1.5 of this video player can be found in the release section of this repo.  It is a 64-bit MS Windows build. If your system complains about missing DLLs after installation, locate the vcredist_x64.exe file in the installation folder and run it to install the missing DLL files.

This player supports ATSC3.0/HEVC video and Dolby AC-4 audio streams by compiling the source code and linking it with an experimental version of ffmpeg that supports Dolby AC-4 audio.  Contact me if you'd like the sources for this experimental version of ffmpeg.

This player was created for people who are early adopters of the new north American ATSC3.0 broadcasting standard.  Most major US cities have conducted a rollout of this new broadcasting standard that supports 4K HEVC video with Dolby AC-4 audio, over-the-air (OTA) television broadcast streams.

For owners of SiliconDust HDHomeRun 4K tuners, viewing an ATSC3.0 video stream is as easy as entering the URL for a particular channel as found in your tuner's channel lineup.  I.e. http://x.x.x.x:5004/auto/vyyy.y  Replace the X's with the IP address of your tuner and replace the Y's with the channel number you want to watch.  Allow 10 to 15 seconds of buffering before the video/audio appears.

This player also supports playback from local files and from rtsp:// camera streams.  For password protected camera streams use this URL as a template for connecting to your camera: rtsp://admin:password@x.x.x.x:554/path-of-your-stream

For cameras not using authentication, use the following template: rtsp://x.x.x.x:554/path-of-your-stream

This player was built using QT5.6.  

Build steps for 64-bit Windows:
1. Open a Visual Studio x64 command prompt and run qmake.
2. Next, run nmake.
3. After a successful build, copy the ffmpeg DLL files into x64/Release folder.
4. Run the windeployqt command to ensure that all the QT DLL's and support files are included in the Release directory.
5. The resulting videoplayer.exe can be run for this directory or bundled with an installer.  See the releases section of the repo for a full installer.
6. After installing, if Windows complains about missing Visual C runtime files, locate vcredist_x64.exe inside the installation folder and run it to install the needed DLL's.




