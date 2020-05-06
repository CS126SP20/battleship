//
// Created by Alekhya on 5/6/2020.
//

#include <mylibrary/scoredb.h>
//#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

namespace mylibrary {

using std::string;
using std::vector;

// See examples: https://github.com/SqliteModernCpp/sqlite_modern_cpp/tree/dev

/*
LeaderBoard::LeaderBoard(const string& db_path) : battleship_db_{db_path} {
  battleship_db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  name  TEXT NOT NULL,\n"
         "  score INTEGER NOT NULL\n"
         ");";
}

void LeaderBoard::AddScoreToLeaderBoard(const Player& player) {
  std::string player_name = player.name;
  size_t player_score = player.score;
  battleship_db_ << "INSERT INTO leaderboard (name, score) "
         "VALUES (?,?);"
      << player_name
      << player_score;
}

vector<Player> GetPlayers(sqlite::database_binder* rows) {
  vector<Player> players;

  for (auto&& row : *rows) {
    string name;
    size_t score;
    row >> name >> score;
    Player player = {name, score};
    players.push_back(player);
  }

  return players;
}

vector<Player> LeaderBoard::RetrieveHighScores(const size_t limit) {
  size_t num_limit = limit;
  auto rows = battleship_db_ << "SELECT name, score "
                     "FROM leaderboard "
                     "ORDER BY score DESC "
                     "LIMIT ?;"
                  << num_limit;

  return GetPlayers(&rows);
}

vector<Player> LeaderBoard::RetrieveHighScores(const Player& player,
                                               const size_t limit) {
  std::string player_name = player.name;
  size_t num_limit = limit;
  auto rows = battleship_db_ << "SELECT name, score "
                     "FROM leaderboard "
                     "WHERE player_name "
                     "ORDER BY score DESC "
                     "LIMIT ?;"
                  << num_limit;

  return GetPlayers(&rows);
}*/

}  // namespace mylibrary
