#include <iostream>
#include <string>

class AbstractProductA {
    public:
        virtual std::string UseFulFunctionA() const = 0;
};

class ConCreteProductA1 : public AbstractProductA {
    public:
        std::string UseFulFunctionA() const override {
            return "Product A1 have created";
        }

};

class ConCreteProductA2 : public AbstractProductA {
    public:
        std::string UseFulFunctionA() const override {
            return "Product A2 have created";
        }

};

class AbstractProductB {
    
    public:
        virtual std::string UseFulFunctionB() const = 0;
        virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConCreteProductB1 : public AbstractProductB {
    public:
        std::string UseFulFunctionB() const override{
            return "Product B1 have created";
        }

        std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
            std::string result = collaborator.UseFulFunctionA();
            return "Product B1 have created and  " + result;
        }
};

class ConCreteProductB2 : public AbstractProductB {
    public:
        std::string UseFulFunctionB() const override{
            return "Product B have created";
        }

        std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
            std::string result = collaborator.UseFulFunctionA();
            return "Product B1 have created and  " + result;
        }
};

class AbstractFactory {
    public:
        virtual AbstractProductA *CreateProductA() const = 0;
        virtual AbstractProductB *CreateProductB() const = 0;
};

class ConCreteFactory1 : public AbstractFactory {
    public:
        AbstractProductA *CreateProductA() const override {
            return new ConCreteProductA1();
        }

        AbstractProductB *CreateProductB() const override {
            return new ConCreteProductB1();
        }
};

class ConCreteFactory2 : public AbstractFactory {
    public:
        AbstractProductA *CreateProductA() const override {
            return new ConCreteProductA2();
        }

        AbstractProductB *CreateProductB() const override {
            return new ConCreteProductB2();
        }
};

void client(AbstractFactory &factory){
    const AbstractProductA *product_A = factory.CreateProductA();
    const AbstractProductB *product_B = factory.CreateProductB();

    std::cout << product_B->UseFulFunctionB();
    std::cout << product_B->AnotherUsefulFunctionB(*product_A);

    delete product_A;
    delete product_B;

}

int main(){
    ConCreteFactory1 *f1 = new ConCreteFactory1();
    client(*f1);
    return 0;
}