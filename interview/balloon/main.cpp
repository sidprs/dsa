#include <vector>
#include <map>


/*

    - stable going up
    - immediately unstable if altitude > 15 m/s
    - unstable baloon can regain stableif remains at an altitude with safe wind speed below threshold
      [ for at least 300 seconds]

    - WindSpeed(h) = WindSpeedAltitude / (1 + ((h - WindAltitude) / 100)^2)
    - h is baloon altitude

    - WindSpeedAltitude is wind speed at that altitude

*/


class BaloonFestival{

  public:

  bool balloonAscended(double timestamp, const std::string& balloonName, double altitude){
    return false;
  }

  bool baloonDescended(double timestamp, const std::string& balloonName){
    return false;
  }

  bool setWindSpeed(double timestamp, double altitude, double windspeed){
    return false;
  }

  std::vector<std::string> inspectBalloons(double timestamp){
    return {};
  }

  private:


};

