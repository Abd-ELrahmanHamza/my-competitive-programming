/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class FoodRatings {
public:
    unordered_map<string, int> foodRatings;
    unordered_map<string, string> foodCuisines;

    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> cuisinesFoodsPQS;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for (int i = 0; i < foods.size(); i++) {
            foodCuisines[foods[i]] = cuisines[i];
            foodRatings[foods[i]] = ratings[i];
            cuisinesFoodsPQS[cuisines[i]].push({ ratings[i], foods[i] });
        }
    }

    void changeRating(string food, int newRating)
    {
        foodRatings[food] = newRating;
        cuisinesFoodsPQS[foodCuisines[food]].push({ newRating, food });
    }

    string highestRated(string cuisine)
    {
        auto t = cuisinesFoodsPQS[cuisine].top();
        while (t.first != foodRatings[t.second]) {
            cuisinesFoodsPQS[cuisine].pop();
            t = cuisinesFoodsPQS[cuisine].top();
        }

        return t.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end
