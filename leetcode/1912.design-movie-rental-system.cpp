/*
 * @lc app=leetcode id=1912 lang=cpp
 *
 * [1912] Design Movie Rental System
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MovieRentingSystem {
public:
    struct Movie {
        int price, shop, movie;
    };
    unordered_map<int, unordered_map<int, bool>> movieStatus;
    unordered_map<int, unordered_map<int, int>> moviePrice;
    struct MovieCompare {
        bool operator()(const Movie& a, const Movie& b) const
        {
            if (a.price != b.price)
                return a.price > b.price;
            if (a.shop != b.shop)
                return a.shop > b.shop;
            return a.movie > b.movie;
        }
    };
    priority_queue<Movie, vector<Movie>, MovieCompare> rentedMovies;
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> unrentedMovies;
    MovieRentingSystem(int n, vector<vector<int>>& entries)
    {
        //[shopi, moviei, pricei]
        for (auto v : entries) {
            movieStatus[v[0]][v[1]] = true;
            moviePrice[v[0]][v[1]] = v[2];
            unrentedMovies[v[1]].push({ v[2], v[0] });
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;
        vector<pair<int, int>> temp;
        while (!unrentedMovies[movie].empty() && res.size() < 5) {
            auto t = unrentedMovies[movie].top();
            temp.push_back(t);
            unrentedMovies[movie].pop();
            if (movieStatus[t.second][movie]) {
                if ((!res.empty() && res[res.size() - 1] != t.second) || res.empty()) {
                    res.push_back(t.second);
                }
            }
        }
        for (auto t : temp)
            unrentedMovies[movie].push(t);
        return res;
    }

    void rent(int shop, int movie)
    {
        movieStatus[shop][movie] = false;
        rentedMovies.push({ moviePrice[shop][movie], shop, movie });
    }

    void drop(int shop, int movie)
    {
        movieStatus[shop][movie] = true;
        unrentedMovies[movie].push({ moviePrice[shop][movie], shop });
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;
        vector<Movie> temp;
        while (!rentedMovies.empty() && res.size() < 5) {
            auto t = rentedMovies.top();
            temp.push_back(t);
            rentedMovies.pop();
            if (!movieStatus[t.shop][t.movie]) {
                if ((!res.empty() && !(res[res.size() - 1][0] == t.shop && res[res.size() - 1][1] == t.movie)) || res.empty()) {
                    res.push_back({ t.shop, t.movie });
                }
            }
        }
        for (auto t : temp)
            rentedMovies.push(t);
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end
