//
// Created by Alekhya on 5/6/2020.
//

#ifndef FINALPROJECT_SCOREDB_H
#define FINALPROJECT_SCOREDB_H

//#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

namespace mylibrary {

class LeaderBoard {
 private:
  //sqlite::database battleship_db_;

 public:
  // Creates a new leaderboard table if it doesn't already exist.
  explicit LeaderBoard(const std::string& db_path);

  // Adds a player to the leaderboard.
  //void AddScoreToLeaderBoard(const Player&);

  // Returns a list of the players with the highest scores, in decreasing order.
  // The size of the list should be no greater than `limit`.
 // std::vector<Player> RetrieveHighScores(const size_t limit);

  // Returns a list of the players with the highest scores, in decreasing order,
  // that have the same `name` as the input player name.
  // The size of the list should be no greater than `limit`.
  //std::vector<Player> RetrieveHighScores(const Player&, const size_t limit);

};

}  // namespace mylibrary

#endif  // FINALPROJECT_SCOREDB_H
