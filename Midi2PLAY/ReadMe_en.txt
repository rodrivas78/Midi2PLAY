
			Midi2PLAY v.1.0  (for Windows 32/64)
	                        by Rodrivas78 



Summary:
1. Introduction
2. Compatibility
3. Quick guide
4. Formatting (file "mml.txt")
5. Example of use
6. Concatenating bars
7. Tips
8. Limitations and Known Issues
9. Final considerations



1. Introduction

 "Midi2PLAY" is an application that helps the process of converting MIDI files (.mid) making them compatible with the syntax accepted by the "PLAY" command of MSX-BASIC.

 This program works as an extension of the "3ML Editor" program, that is, it depends on this one to carry out the conversion process. The 3ML Editor is free and can be downloaded at the link: http://3ml.jp/download.html (At the moment this manual is written it is in the version: 2.0.3)

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

                                                  
3. Quick Guide / Quick Guide

The conversion of the MIDI file occurs in two steps:

1) In the 3ML Editor you import the MIDI file (.mid) (File> Import Standar MIDI file).

Note: If the file has more than 3 tracks (or channels), you will have to choose only 3 of them, because it is the maximum that MSX PSG supports.

2) Also in the 3ML Editor write down the octave of the first note of each "track". This information can be obtained by placing the mouse pointer over the first note of each "track" on the grid, on the right side of the virtual piano (see attached image: "getting_octave.png"). When you hover over the note, a balloon (in the "same color" of the track) will appear with the octave number after the letter "o", (example: something like "O5 V8 Gate24" will appear, this means that the note is in octave 5). Do this for each of the channels/tracks.

3) Still in the 3ML Editor, export the MML (as type "MabiMML Compatible Format") to the clipboard ("File> Export MML to Clipboard"). Select (in the export window on the left) the tracks that will be exported.
4) Paste the file into the notepad and save it as "mml.txt".
5) Move this file ("mml.txt") to the folder where Midi2PLAY is.
6) It is now necessary to make a quick formatation in the file so that it can be read correctly by Midi2PLAY.


4. Formatting (the file "mml.txt")
 
    ------------------------------------------------- Formatting ------------------------------------------------------

  This step is very important. If the file "mml.txt" is not formatted correctly Midi2PLAY will not be able to convert the file.

  It is recommended that along with these formatation instructions, you see the files in the "Formatation Examples" folder. The files referenced in this section are present in this folder.

Formatting consists of two steps:

1) Remove from the file "mml.txt" other than the string lines and "[Channel]" (see "formatting_step1.jpg").
2) Erase the duplicate measure indications (see "formatting_step2.jpg", EXAMPLE 1 below and the "Tips" section of this manual).

3) Do not forget to keep the character "]" at the end of the document.

  If there is any indication of duplicate measure, you will have to remove it manually from the file "mml.txt":

EXAMPLE 1 - Removing Duplicates in Measure (Bar number) Indications

See below that there are two "/* M 1 */" inside on channel 1.

---------------------------------- "mml.txt" ----------------------------------
[Channel1]
/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
/*M 1  */  r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16
...
------------------------------------------------------------------------------

After running "Midi2PLAY" the file "temp.txt" will contain the following output:

----------------------------"temp.txt" ---------------------------------------

[C1] / * M1 * / [C2] [C3]

--------------------------------------------------------------------------------

This informs that / * M1 * / is duplicated on channel 1 ("[C1]")

Edit the file by deleting only the second "/ * M 1 * /". The result should be (more or less) like this:

-----------------------------------"mml.txt"------------------------------------------------

[Channel1]
/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
           r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16
...
---------------------------------------------------------------------------------------------


Note: It does not matter the tabulation (amount of spaces) left. Just delete the second "/* M 1 */", from slash to slash.

The formatting phase is now complete, the file is ready to be converted in Midi2PLAY.

----------------------------------------------- end of formatation step --------------------------------------------------

(continuation)
7) After formatting save the file (such as "mml.txt").
8) Run Midi2PLAY again, enter the data as the program requests: whether or not you want to concatenate the bars (see EXAMPLE 3, below) and then the octave (just the numbers) in which each channel starts. Just enter each value and hit ENTER.
9) The result can be seen in the file "play.txt".
10) Finally, delete the "[Channel]" indications and initialize the arrays and loop (for / next), as below (EXAMPLE 2), and save the file as ".BAS".



 5.   Example of use:

Below we have the file "play.txt", which is nothing more than the "mml_ready.txt" (from the folder "Formatation Examples") after conversion done by Midi2PLAY. It is a polyphonic song with 3 channels / tracks.



---------------------------------------- "play.txt" -------------------------------------------------

[Channel1]
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8"
20 A$(2)="f16e8.d8.d+8.d8c16o4a+8."
30 A$(3)="o5d+8.a+8.g8d+16d8.g8e4"
40 A$(4)="e16"
[Channel2]
50 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8"
60 B$(2)="o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
70 B$(3)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4"
80 B$(4)="a16"
[Channel3]
90 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8"
100 C$(2)="f16e8c16g8b16o6c8o5a+16g+8g16f8"
110 C$(3)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4"
120 C$(4)="d16" 

-----------------------------------------------------------------------------------------------------

As you can see our program in BASIC is almost ready, we already have in the file "play.txt" the lines and matrices with the strings of each channel. We now only need to delete the "[Channel ]", initialize the matrices and create a loop to generate simultaneous execution of each channel:

EXAMPLE 2

------------------------------------------- "GALAGA.BAS" - --------------------------------------------------

5 DIM A$(4): DIM B$(4): DIM C$(4)
7 T$="s9m50000t100"
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8"
20 A$(2)="f16e8.d8.d+8.d8c16o4a+8."
30 A$(3)="o5d+8.a+8.g8d+16d8.g8e4"
40 A$(4)="e16"
50 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8"
60 B$(2)="o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
70 B$(3)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4"
80 B$(4)="a16"
90 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8"
100 C$(2)="f16e8c16g8b16o6c8o5a+16g+8g16f8"
110 C$(3)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4"
120 C$(4)="d16" 
2000 PLAY T$, T$, T$
2010 FOR X=1 to 4
2020 PLAY A$(X), B$(X), C$(X)
2030 NEXT X
-------------------------------------------------------------------------------------------

Now just save it as .BAS for use in MSX.

------------------------------------------------------------------------------------------------ 


6. Concatenating bars.

In Midi2PLAY there is the option of choosing whether or not you want to concatenate the bars.
If the option to concatenate bars is selected, you will be asked how many bars per line. You can concatenate 2, 3 or 4 bars per line.

Below the same "mml_ready.txt" but here was chosen concatenation of 2 bars per line:

EXAMPLE 3

[Channel1]
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8f16e8.d8.d+8.d8c16o4a+8."
20 A$(2)="o5d+8.a+8.g8d+16d8.g8e4e16"
[Channel2]
30 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
40 B$(2)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4a16"
[Channel3]
50 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8f16e8c16g8b16o6c8o5a+16g+8g16f8"
60 C$(2)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4d16" 

Note: When selecting this option, care must be taken that the string does not exceed 255 characters, as this is the maximum string size supported by MSX-BASIC.

---------------------------------------------------------------------------------------------------------------------


7. Tips:

Automatically discover duplicate measure indications.

    To automatically find out which measure (or bar) number indications, first leave the file as seen in "formatting_step2.jpg". Perform Midi2PLAY (choose: not concatenate bars and any value for the octaves). The program will generate the file "temp.txt", in it can be seen duplicate indications. If there is no * M * in "temp.txt" there are no duplicate indications. Obs3 .: This method is useful for long songs, with many measures, where it becomes difficult and laborious to look for duplications in each of the tracks.


8. Limitations and known issues.

  It is necessary to alert users that the program still has some limitations. In the current version it has been consistent in converting many of the "mml" files generated by 3ML Editor, however some may still have inaccuracies in the conversion.

Among the most frequent problems are:

8.1) Imprecise octave definitions.
When you run Midi2Play, the application asks you to enter the octave of the initial note and use it as a reference, converting all subsequent notes, respecting the octave changes indicated by the ">" or "<" signs. Some of these symbols can be "duplicated" and the result is that after conversion, the track will sound an octave above or an octave below.
  
  This problem is easily circumvented if the user manually edit the "mml.txt" file where the problem occurs (usually near the beginning of some channel). You can force the correct octave by manually deleting one or other "<" or ">" symbols or by entering the letter "o" and the correct octave number (for example: "o5"). You can also enter another octave of the initial note (reference note) when running Midi2Play.

8.2) Unwanted pauses.
Another problem that may appear and this is only noticeable after listening to the converted music, is the appearance of unwanted pauses in the course of the execution. This usually occurs in some midi files where the 3ML Editor truncates the voices, making some of the pauses too long in relation to the "measures" it creates.
 To work around this problem there are three possible solutions:
1) Attempt to find another Midi file of the song you want to convert (a file in which each track is correctly edited or separated) *.
2) Choose a different concatenation of bars (2 to 4 bars per line). This action is done automatically by the program (see section 5 or EXAMPLE 3 of this manual).
3) Another solution is to "fix" the file manually, finding the long pauses near the end of the measure. Decreasing the amount of this pause causes the music to flow normally.

* Not all ".mid" files are usable. Depending on the file the channels may be truncated which will cause the 3ML Editor not to open properly. Look for files that contain the separate voices (such as at this link: http://stringsound.com/Page12.html).

Synchronization problems between tracks:
Some misplaced pauses (by 3ML Editor) can also generate a lack of synchronization between tracks. This lack of timing is usually brief and lasts for one or two measures.

Some polyphonic songs (2 or more channels) that have anacruse, where the initial pauses are not specified correctly in the .mid file, may exhibit synch problems in some measures during the execution (of the .BAS file).
 A possible solution to this problem is to manually correct the voices (editing the tracks 3ML Editor) in the bars where the anacruse appears, inserting the appropriate pauses in the initial measure of the song.

8.3) Other problems:
If the song was not converted correctly, make sure that all the steps of the formatting were followed exactly.
Example:
Did you properly format the "mml.txt"?
Has the duplicated measure indication (/ M * _ /) been cleared? Check the "temp.txt" file on each conversion to see if there are any.
Did you add the "]" at the end of this document ("mml.txt")?

8.4) Problems (or errors) while running on MSX:

Check to see if any characters remaining in the mml syntax ("[", or "[Channel]" or "]" have been deleted).
Verify that you have correctly sized the matrices for each voice.
See if any line has exceeded 255 characters since this is the maximum string size supported by MSX-BASIC. Too long strings can also generate a small delay and compromise the timing a bit.

If there is any discrepancy in relation to the octave. Make sure each track / channel of the converted file starts with the correct octave.

     You can also change some parameters at the time of importing the Midi file ("Import Settings" in the 3ML Editor): Select: reduce rest.

 If the file or music has many ornaments or quick notes (that causes the music to suffer "small fires" at the moment they are MSX), try lowering the "Quantization Settings" when importing them into the 3ML Editor (in the "Import Settings" window). For example if you are on 1/64 change to 1/32, or change from 1/32 to 1/16. 

Final considerations:

 I have not had time to perform all the necessary tests, so if possible help by reporting any bug to the following e- mail: rrivas2009@gmail.com. Reviews and suggestions are also welcomed!


---------------------------------------------------------------------------------------------

Copyright 2018 Rodrivas78

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


