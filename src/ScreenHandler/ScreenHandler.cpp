#include "ScreenHandler.h"

ScreenHandler::ScreenHandler()
    : lcd(NULL, NULL, NULL, NULL, NULL, NULL), actionHandler(NULL)
{
}

ScreenHandler::~ScreenHandler()
{
}

void ScreenHandler::Init(const uint8_t pins[6], uint8_t aPin, Pair<uint8_t, uint8_t> menuDimensions)
{
    menuPosition = MenuPosition(Pair<uint8_t, uint8_t>(0, 0), menuDimensions);
    actionHandler = ActionHandler(aPin);

    lcd = LiquidCrystal(pins[0], pins[1], pins[2], pins[3], pins[4], pins[5]);
    lcd.begin(16, 2);
    lcd.clear();
}

void ScreenHandler::Update(String menuLines[3][2])
{
    PrintMenu(menuLines);
    SetMenuPosition();
}

void ScreenHandler::PrintMenu(String menuLines[3][2])
{
    lcd.clear();
    lcd.print(">");
    lcd.print(menuLines[menuPosition.GetCategory()][menuPosition.GetItem()]);
    lcd.setCursor(1, 1);
    lcd.print(menuLines[menuPosition.GetCategory()][menuPosition.GetNextItem()]);
}

void ScreenHandler::SetMenuPosition()
{
    uint8_t pressedKey = actionHandler.GetKey();

    switch (pressedKey)
    {
    case UP_KEY:
        menuPosition.SetPreviousItem();
        break;
    case DOWN_KEY:
        menuPosition.SetNextItem();
        break;
    case LEFT_KEY:
        menuPosition.SetPreviousCategory();
        break;
    case RIGHT_KEY:
        menuPosition.SetNextCategory();
        break;
    case SELECT_KEY:
        break;
    default:
        break;
    }

    Serial.println("Current position: ");
    Serial.println(menuPosition.GetCategory());
    Serial.println(menuPosition.GetItem());
    Serial.println();

    Serial.println("Next position: ");
    Serial.println(menuPosition.GetCategory());
    Serial.println(menuPosition.GetNextItem());
    Serial.println();
}