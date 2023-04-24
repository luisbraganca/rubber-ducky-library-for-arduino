#ifndef Rubber_Ducky
#define Rubber_Ducky

#include "Keyboard.h"

class RubberDucky {
public:
    RubberDucky();
    /**
     * Prepares the virtual keyboard.
     * This method should be the first instruction on the setup code block.
     */
    void start();
    /**
     * Ends the virtual keyboard.
     * This method should be the last instruction on the setup code block.
     */
    void finish();

    /**
     * For the keyboard functions to work they need a small
     * delay between them. If you notice there's some bugs
     * when running your arduino, try using different delay values
     * on this function.
     */
    void wait();

    /**
     * A longer delay (5 times the regular delay).
     */
    void longerWait();

    /**
     * Writes a text.
     * @param text The text to write.
     */
    void writeText(String text);

    /**
     * Used to type non-alphanumeric keys.
     * @param key The key to type.
     */
    void typeKey(uint8_t key);

    /**
     * Runs a program.
     * Example: "notepad" starts notepad, "calc" starts the calculator.
     * @param program The program to run.
     */
    void run(String program);

    /**
     * Takes a screenshot.
     */
    void printScreen();

    /**
     * Opens the JavaScript console on a browser.
     */
    void openJavascriptConsole();

    /**
     * Hides a window:
     * Basically it drags a window to the lowest it can be
     * and then repositions the cursor.
     */
    void hideWindow();

    /**
     * Same as Win + D
     */
    void showDesktop();

    /**
     * Same as Ctrl + V
     */
    void paste();

    /**
     * Same as Ctrl + X
     */
    void cut();

    /**
     * Same as Ctrl + C
     */
    void copy();

    /**
     * Same as Gui + (the received key)
     * @param c The key to press.
     */
    void guiCombination(uint8_t c);

    /**
     * Same as Alt + (the received key)
     * @param c The key to press.
     */
    void altCombination(uint8_t c);

    /**
     * Same as Ctrl + (the received key)
     * @param c The key to press.
     */
    void ctrlCombination(uint8_t c);

    /**
     * Same as Shift + (the received key).
     * @param c The key to press.
     */
    void shiftCombination(uint8_t c);

    /**
     * Same as (Received hold key) + (target key).
     * @param holdKey The key to hold.
     * @param targetKey The key to press.
     */
    void keyCombination(uint8_t holdKey, uint8_t targetKey);

    /**
     * Same as (Received hold key 1) + (received hold key 2) + (target key).
     * @param holdKey1
     * @param holdKey2
     * @param targetKey
     */
    void keyCombination(uint8_t holdKey1, uint8_t holdKey2, uint8_t targetKey);

    /**
     * Same as above but with one more hold key.
     * @param holdKey1
     * @param holdKey2
     * @param holdKey3
     * @param targetKey
     */
    void keyCombination(uint8_t holdKey1, uint8_t holdKey2, uint8_t holdKey3, uint8_t targetKey);

    /**
     * Opens the command prompt without admin rights.
     */
    void openCommandPrompt();

    /**
     * Opens the command prompt, if the "admin" parameter
     * has a "true value", it opens a command prompt
     * with admin rights. Or without admin rights otherwise.
     * @param admin
     */
    void openCommandPrompt(boolean admin);

    /**
     * Accepts the windows smart screen to grant admin permissions.
     */
    void acceptWindowsSmartScreen();

    /**
     * Changes the keyboard layout, if the computer only
     * has 1 keyboard layout this key combination won't
     * do anything.
     */
    void changeKeyboardLayout();

    /**
     * It runs one or multiple powershell scripts,
     * to run multiple scripts, separate them with a new line "\n" char.
     * @param scripts The scripts to run.
     */
    void powershellRun(String scripts);
};

#endif
