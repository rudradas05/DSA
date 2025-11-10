class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long pMass = mass;
        if(mass<asteroids[0]){
            return false;
        }
        for(int i = 0 ; i<asteroids.size(); i++){
            if(pMass>=asteroids[i]){
                pMass = pMass+asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};