# VideoPlayer
# Qt+ffmpeg+SDL2+Dolby+AC-4+AC4+HEVC+ATSC3.0+4K+video 

This is a fork of the video player found here:  https://github.com/yundiantech/VideoPlayer

This fork has been updated to support Dolby AC-4 audio streams by compiling it against an experimental version of ffmpeg that supports Dolby AC-4 audio.
You can find the experimental verion of ffmpeg here:  https://github.com/richardpl/FFmpeg/tree/ac4

This fork was created for people who are early adopters of the new north American ATSC3.0 broadcasting standard.  Most major US cities have conducted a rollout of this new boradcasting standard that supports 4K HEVC, over-the-air (OTA), television broadcast streams.

For owners of SiliconDust HDHomeRun 4K tuners, vieweing an ATSC3.0 video stream is as easy as entering the URL for a particular channel as found in your tuner's channel lineup.  I.e. http://x.x.x.x:5004/auto/vyyy.y  Replace the X's with the IP address of your tuner and replace the Y's with the channel number you want to watch.  Allow 10 to 15 seconds of buffering before the video/audio appears.

This player also supports playback from local files and from rtsp:// camera streams.  For password protected camera streams use this URL as a template for connectiog to your camera: rtsp://admin:password@x.x.x.x:554/path-of-your-stream
For cameras not using authentication use the following template: rtsp://x.x.x.x:554/path-of-your-stream

This player was built using QT5.6.  

Build steps for 64-bit Windows:
1. Open a visual Studio x64 command propt and run qmake
2. Next, run nmake
3. After a successful build, copy the ffmpeg DLL files into x64/Release folder.
4. Run the windeployqt command to ensure that all the QT DLL's and support files are included in the Release directory
5. The resulting videoplayer.exe can be run for this directory or bundled with an installer


Build steps for Linux or MacOS
1. Download, build, and install ffmpeg from the experimantal branch I mentioned above as well as SDL2
2. Run qmake
3. Run the make command
4. Run the linuxdeployqt or macdeployqt command depending on your platform
