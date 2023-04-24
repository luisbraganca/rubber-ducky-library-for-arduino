#include "Keyboard.h"
#include "Rubber_Ducky.h"

RubberDucky::RubberDucky() {}

void RubberDucky::start() {
    Keyboard.begin();
    longerWait();
}

void RubberDucky::finish() {
    Keyboard.end();
}

void RubberDucky::wait() {
    delay(100);
}

void RubberDucky::longerWait() {
    delay(500);
}

void RubberDucky::writeText(String text) {
    Keyboard.print(text);
    wait();
}

void RubberDucky::typeKey(uint8_t key) {
    Keyboard.press(key);
    wait();
    Keyboard.release(key);
    wait();
}

void RubberDucky::run(String program) {
    guiCombination('r');
    Keyboard.print(program);
    wait();
    typeKey(KEY_RETURN);
}

void RubberDucky::printScreen() {
    // some machines use 206 key as the PrtScreen key
    // others might use 229, and others might use both so
    // we use both instructions
    typeKey(206);
    typeKey(229);
    Keyboard.print(F("h"));
    wait();
    Keyboard.print(F("b"));
    wait();
}

void RubberDucky::openJavascriptConsole() {
    keyCombination(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 'i');
}

void RubberDucky::hideWindow() {
    altCombination(' ');
    Keyboard.print(F("M"));
    wait();
    Keyboard.press(KEY_DOWN_ARROW);
    // 100 should be enough to guarantee the window is as low as possible
    // also please notice that 100 is not the real number of strokes since
    // some of the strokes are ignored.
    for(int i = 0; i < 10; i++) longerWait();
    Keyboard.release(KEY_DOWN_ARROW);
    // return repositions the cursor back to its original position
    typeKey(KEY_RETURN);
}

void RubberDucky::showDesktop() {
    guiCombination('d');
}

void RubberDucky::paste() {
    ctrlCombination('v');
}

void RubberDucky::cut() {
    ctrlCombination('x');
}

void RubberDucky::copy() {
    ctrlCombination('c');
}

void RubberDucky::guiCombination(uint8_t c) {
    keyCombination(KEY_LEFT_GUI, c);
}

void RubberDucky::altCombination(uint8_t c) {
    keyCombination(KEY_LEFT_ALT, c);
}

void RubberDucky::ctrlCombination(uint8_t c) {
    keyCombination(KEY_LEFT_CTRL, c);
}

void RubberDucky::shiftCombination(uint8_t c) {
    keyCombination(KEY_LEFT_SHIFT, c);
}

void RubberDucky::keyCombination(uint8_t holdKey, uint8_t targetKey) {
    Keyboard.press(holdKey);
    wait();
    Keyboard.press(targetKey);
    wait();
    Keyboard.releaseAll();
    wait();
}

void RubberDucky::keyCombination(uint8_t holdKey1, uint8_t holdKey2, uint8_t targetKey) {
    Keyboard.press(holdKey1);
    wait();
    keyCombination(holdKey2, targetKey);
}

void RubberDucky::keyCombination(uint8_t holdKey1, uint8_t holdKey2, uint8_t holdKey3, uint8_t targetKey) {
    Keyboard.press(holdKey1);
    wait();
    keyCombination(holdKey2, holdKey3, targetKey);
}

void RubberDucky::openCommandPrompt() {
    openCommandPrompt(false);
}

void RubberDucky::openCommandPrompt(boolean admin) {
    if (admin) {
        guiCombination('x');
        Keyboard.print(F("a"));
        acceptWindowsSmartScreen();
    } else {
        run("cmd");
    }
}

void RubberDucky::acceptWindowsSmartScreen() {
    // Wait untill smart screen shows up
    longerWait();
    typeKey(KEY_LEFT_ARROW);
    wait();
    Keyboard.print(F(" "));
    wait();
}

void RubberDucky::changeKeyboardLayout() {
    altCombination(KEY_LEFT_SHIFT);
}

void RubberDucky::powershellRun(String scripts) {
    char delimiter = '\n';
    String finalScript = "powershell ";
    while (scripts.indexOf('\n') > 0) {
        finalScript = finalScript + "(" + scripts.substring(0, scripts.indexOf('\n')) + ") ; ";
        scripts = scripts.substring(scripts.indexOf('\n') + 1);
    }
    finalScript = finalScript + "(" + scripts + ")";
    run(finalScript);
}

