//
// Created by Alekhya on 5/2/2020.
//

#ifndef FINALPROJECT_SHIP_H
#define FINALPROJECT_SHIP_H

#include <string>

namespace mylibrary {
class Ship {
 private:
  //ship size
  int size_;

  //total ship counter
  int counter_;

  //ship name
  std::string name_;
 public:
   /**
   * Default Ship Constructor
   */
    Ship();

    /**
     * Overloaded Constructor
     * @param name - ship name
     * @param size - ship size
     */
    Ship(std::string name, int size);

    /**
     * Sets the counter to make the ship sink
     * @param counter - ship counter
     */
    void SetCounter(int counter);

    /**
     * Gets the ship counter
     * @return counter
     */
    int GetCounter();

    /**
     * Sets the ship size
     * @param size - ship size
     */
    void SetSize(int size);

    /**
     * Gets the ship size
     * @return size
     */
    int GetSize();

    /**
     * Sets the ship name
     * @param name - ship name
     */
    void SetName(std::string name);

    /**
     * Gets the ship name
     * @return name
     */
    std::string GetName();
};

} //namespace mylibrary

#endif  // FINALPROJECT_SHIP_H
