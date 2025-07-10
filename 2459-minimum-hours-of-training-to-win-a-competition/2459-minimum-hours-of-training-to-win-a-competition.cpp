class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
      int n = energy.size();
      int train = 0;
      int totalEnergy = accumulate(energy.begin(), energy.end(),0);
      if(initialEnergy <= totalEnergy)
        train += totalEnergy - initialEnergy + 1;

      for(int i = 0; i < n; ++i) {     
        if(initialExperience <= experience[i]) {
          int hour = experience[i] - initialExperience + 1;
          train += hour;
          initialExperience +=  hour;
        }
        initialExperience += experience[i];
      }
      
      return train;
    }
};

/*
Defeat opponents get experience
the total energy for defeating  enemy is fixed and you can't get energy from others
the totla energy is sum(energy) +1


corner case

energy exp
10000   2
3       10
2       10
2       12


2       100
3       15

using prefix sum to solve the experience problem 

Q
1. will different enermy got same exp ?
2. enery and exp all positive ?

*/