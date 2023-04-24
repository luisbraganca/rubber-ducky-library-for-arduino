#include <Rubber_Ducky.h>

void setup() {
    RubberDucky rd;
    rd.start();

    rd.run("notepad");
    rd.writeText("Hello World!");
    rd.altCombination(' ');
    rd.typeKey('x');
    rd.altCombination('o');
    rd.typeKey('f');
    rd.typeKey(KEY_TAB);
    rd.typeKey(KEY_TAB);
    rd.writeText("200");
    rd.typeKey(KEY_RETURN);

    rd.finish();
}

void loop() {}

