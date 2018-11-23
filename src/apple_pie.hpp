class ApplePie {
public:
    ApplePie();
    int fill();
    void bake();
    int eat();

    bool isFilled(){return filled;}
    bool isBaked(){return baked;}
    bool isBurned(){return burned;}

private:
    bool filled;
    bool baked;
    bool burned;
};
