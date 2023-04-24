#include <Rubber_Ducky.h>

void setup() {
    RubberDucky rd;
    rd.start();


    // NOTE, when uploading this script to your arduino
    // it will be automatically ran, to abort the shutdown you have
    // 60 seconds, open command prompt and type:
    // shutdown -a
    rd.openCommandPrompt();
    rd.hideWindow();
    rd.writeText("shutdown /s /t 60");
    rd.typeKey(KEY_RETURN);
    rd.longerWait();
    rd.typeKey(KEY_RETURN);
    rd.longerWait();
    rd.writeText("exit");
    rd.typeKey(KEY_RETURN);

    rd.finish();
}

void loop() {}

