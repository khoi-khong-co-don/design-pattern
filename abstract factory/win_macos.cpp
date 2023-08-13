#include <iostream>
#include <string>

class Button {
    public:
        virtual std::string UseButton() const = 0;
};

class Checkbox {
    public:
        virtual std::string UseCheckbox() const = 0;
};

class WinButton : public Button {
    public:
        std::string UseButton() const override{
            return "Use button on WIN";
        }
};

class WinCheckBox : public Checkbox {
    public:
        std::string UseCheckbox() const override{
            return "Use checkbox on WIN";
        }
        
};

class MacButton: public Button {
    public:
        std::string UseButton() const override{
            return "Use button on MAC OS";
        }
};

class MacCheckBox : public Checkbox {
    public:
        std::string UseCheckbox() const override{
            return "Use checkbox on MAC OS";
        }
};

class GUIFactory {
    public:
        virtual Button *CreateButton() const = 0;
        virtual Checkbox *CreateCheckbox() const = 0;
};

class WinFactory : public GUIFactory {
    public:
        Button *CreateButton() const override {
            return new WinButton();
        }

        Checkbox *CreateCheckbox() const override {
            return new WinCheckBox();
        }
};

class MacFactory : public GUIFactory {
    public:
        Button *CreateButton() const override {
            return new MacButton();
        }

        Checkbox *CreateCheckbox() const override {
            return new MacCheckBox();
        }
};

void client(const GUIFactory &factory){
    const Button *button = factory.CreateButton();
    const Checkbox *checkbox = factory.CreateCheckbox();

    std::cout << button->UseButton() << std::endl;
    std::cout << checkbox->UseCheckbox() << std::endl;

}

int main(){
    const WinFactory *win = new WinFactory();
    client(*win);

    const MacFactory *mac = new MacFactory();
    client(*mac);
    return 0;
}