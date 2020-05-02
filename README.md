# Midi2PLAY

Update:
On Windows 10 (64 bits) use version 1.2.0

Midi2PLAY is an application (for Windows 32/64) that helps the process of converting MIDI files (.mid) making them compatible with the syntax accepted by the "PLAY" command of MSX-BASIC.

For complete instructions see "Read_Me" file (https://github.com/rodrivas78/Midi2PLAY/blob/master/Midi2PLAY/ReadMe_en.txt)

  Overview

 This program works as an extension of the "3ML Editor" program, that is, it depends on this one to carry out the conversion process. The 3ML Editor is free and can be downloaded at the link: http://3ml.jp/download.html

  Summary of conversion process:

 MIDI file -> 3ML Editor -> MML file (.txt) -> Midi2PLAY -> .BAS file

1) Import the MIDI file into the 3ML Editor.
2) Still in the 3ML Editor: export the MML file. (Save as "mml.txt")
3) Run "Midi2PLAY" (with "mml.txt" in the same folder, properly formatted)
4) The file "play.txt" will be generated. Just save it as ".bas" and use it in MSX.

   It is understood that Midi2PLAY could (or should!) be called "mml2play", since its function is the conversion of the syntax "mml" (Music Macro Language) to the syntax accepted by the PLAY command. But because the "MML" format is not so well-known, and for the program's function to become self-explanatory, I chose the current name.


2. Compatibility:
    
  Midi2PLAY is compatible with Windows 32/64 (very soon a version for Mac OS).
  The syntax generated is compatible with any version of MSX (since MSX1).

