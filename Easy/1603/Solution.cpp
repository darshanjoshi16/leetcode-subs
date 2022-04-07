class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        parking.resize(4,0);
        parking[BIG]=big;
        parking[MED]=medium;
        parking[SMALL]=small;
    }
    
    bool addCar(int carType) {
        if(parking[carType]>0) {
            parking[carType]--;
            return true;
        } else {
            return false;
        }
    }
private:
    enum size {
        BIG=1,
        MED=2,
        SMALL=3
    };
    
    vector<int> parking;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
