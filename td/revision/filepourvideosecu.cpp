
// implementation

int const LOWER = 0;

class System {
    int parameter;

    void verification1(int newValue){
        if(newValue > LOWER){
            parameter = newValue;
        }
    }

    void verification2(int newValue){
        parameter = newValue;
    }
    
};

class Postif {
    float value;

    void verification1(float newValue){
        if(newValue >= 0){
            value = newValue;
        }
    }

    void verification2(float newValue){
        if(newValue > -1){
            value = newValue;
        }
    }
    
};