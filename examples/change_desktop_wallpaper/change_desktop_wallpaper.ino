#include <Rubber_Ducky.h>

void setup() {
    RubberDucky rd;
    rd.start();

    rd.changeKeyboardLayout(); // Turns the keyboard. layout to american
    rd.powershellRun(
            "Start-BitsTransfer -Source 'http://goo.gl/vzqBFS' -Destination ($env:USERPROFILE + '\\Desktop\\CAT.jpg')\n" // Downloads the image
            "mspaint ($env:USERPROFILE + '\\Desktop\\CAT.jpg')" // Opens the downloaded image on paint
    );
    for (int i = 0; i < 6; i++) rd.longerWait(); // Might need to be changed, depending on the machine's internet speed
    rd.typeKey(KEY_LEFT_ALT); // Activates alt shortcuts
    rd.writeText("f"); // File
    rd.writeText("b"); // Set as desktop background
    rd.altCombination(KEY_F4); // Closes paint
    rd.powershellRun(
            "Remove-Item ($env:USERPROFILE + '\\Desktop\\CAT.jpg')" // Deletes the image
    );
    rd.changeKeyboardLayout(); // Turns the keyboard. layout back to normal

    rd.finish();
}

void loop() {}
