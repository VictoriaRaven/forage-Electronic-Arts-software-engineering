#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <iostream>
#include <vector>
#include <string>

// Forward Declarations
class SocialMediaAccount;
class Follower;
class FanInteraction;
class Game;
class Sponsorship;
class WeatherEvent;
class Team;
class Stadium;
class Reputation;
class EventImpact;
class WeatherEffect;
class Post;
class Athlete;

// Class representing an Athlete
class Athlete {
private:
    std::string name;
    std::string position;
    std::vector<std::string> athleticStats; // E.g., {"speed: 9", "strength: 8"}
    Reputation* reputation;  // 1-to-1 with Reputation
    SocialMediaAccount* socialMediaAccount; // 1-to-1 with SocialMediaAccount
    std::vector<FanInteraction*> fanInteractions; // 1-to-many relationship
    std::vector<Game*> games; // Many-to-many relationship

public:
    Athlete(std::string name, std::string position, std::vector<std::string> athleticStats);

    // Methods (stubs)
    void updateReputation();
    void createContent();
    void engageWithFollowers();
    void adaptToWeather(WeatherEffect* weatherEffect);

    // Getters and Setters
    void setReputation(Reputation* rep);
    void setSocialMediaAccount(SocialMediaAccount* account);
    void addFanInteraction(FanInteraction* interaction);
    void addGame(Game* game);
    std::string getName() const;
    std::string getPosition() const;
};

// Class representing SocialMediaAccount
class SocialMediaAccount {
private:
    std::vector<Follower*> followers; // Many-to-1 with Follower
    double engagementRate;
    std::string accountType;
    std::vector<Post*> posts; // 1-to-many relationship with Post
    std::vector<Sponsorship*> sponsorships; // 1-to-many with Sponsorship

public:
    SocialMediaAccount(double engagementRate, std::string accountType);

    // Methods (stubs)
    void postContent(Post* post);
    void gainFollowers(int numFollowers);
    void loseFollowers(int numFollowers);
    void updateEngagement();

    // Getters and Setters
    void addPost(Post* post);
    void addSponsorship(Sponsorship* sponsorship);
    void addFollower(Follower* follower);
    double getEngagementRate() const;
    std::string getAccountType() const;
};

// Class representing Post
class Post {
private:
    std::string contentType;
    std::string postDate;
    int likes;
    int comments;
    int shares;
    std::vector<FanInteraction*> fanInteractions; // 1-to-many relationship with FanInteraction

public:
    Post(std::string contentType, std::string postDate, int likes, int comments, int shares);

    // Methods (stubs)
    void createPost();
    int getEngagement();
    void calculateReach();

    // Getters and Setters
    void addFanInteraction(FanInteraction* interaction);
    std::string getContentType() const;
    std::string getPostDate() const;
};

// Class representing Follower
class Follower {
private:
    std::string name;
    std::string followerType;
    int engagementLevel;

public:
    Follower(std::string name, std::string followerType, int engagementLevel);

    // Methods (stubs)
    void interactWithPost(Post* post);
    void increaseEngagement();

    // Getters and Setters
    std::string getName() const;
    std::string getFollowerType() const;
    int getEngagementLevel() const;
};

// Class representing Sponsorship
class Sponsorship {
private:
    std::string brandName;
    double contractValue;
    int duration;
    std::string terms;

public:
    Sponsorship(std::string brandName, double contractValue, int duration, std::string terms);

    // Methods (stubs)
    void signContract();
    void renewContract();

    // Getters and Setters
    std::string getBrandName() const;
    double getContractValue() const;
};

// Class representing WeatherEvent
class WeatherEvent {
private:
    std::string weatherType;
    int severity;
    int duration;
    std::string impactOnGameplay;

public:
    WeatherEvent(std::string weatherType, int severity, int duration, std::string impactOnGameplay);

    // Methods (stubs)
    void generateWeatherEvent();
    void applyImpactToGame(Game* game);

    // Getters and Setters
    std::string getWeatherType() const;
    int getSeverity() const;
};

// Class representing Game
class Game {
private:
    std::string gameTime;
    WeatherEvent* weather;
    std::vector<Team*> teamsInvolved;
    std::pair<int, int> score; // {team1_score, team2_score}

public:
    Game(std::string gameTime, WeatherEvent* weather, std::vector<Team*> teamsInvolved);

    // Methods (stubs)
    void startGame();
    void pauseForWeather();
    void simulateWeatherImpact();
    void addTeam(Team* team);

    // Getters and Setters
    std::string getGameTime() const;
    std::pair<int, int> getScore() const;
};

// Class representing Team
class Team {
private:
    std::string teamName;
    std::vector<std::string> teamStats;
    std::vector<Athlete*> players; // 1-to-many relationship with Athlete

public:
    Team(std::string teamName, std::vector<std::string> teamStats);

    // Methods (stubs)
    void setLineup();
    void strategizeForWeather(WeatherEvent* weatherEvent);
    void addPlayer(Athlete* player);

    // Getters and Setters
    std::string getTeamName() const;
};

// Class representing Stadium
class Stadium {
private:
    std::string stadiumName;
    std::string location;
    std::string fieldCondition;

public:
    Stadium(std::string stadiumName, std::string location, std::string fieldCondition);

    // Methods (stubs)
    void updateFieldCondition();

    // Getters and Setters
    std::string getStadiumName() const;
};

// Class representing FanInteraction
class FanInteraction {
private:
    std::string interactionType;
    std::string fanName;
    std::string message;

public:
    FanInteraction(std::string interactionType, std::string fanName, std::string message);

    // Methods (stubs)
    void interact();

    // Getters and Setters
    std::string getFanName() const;
};

// Class representing EventImpact
class EventImpact {
private:
    std::string impactType;
    int severityLevel;
    Athlete* athleteImpact;

public:
    EventImpact(std::string impactType, int severityLevel, Athlete* athleteImpact);

    // Methods (stubs)
    void applyImpact();

    // Getters and Setters
    std::string getImpactType() const;
};

// Class representing Reputation
class Reputation {
private:
    int reputationScore;
    int fansSupport;

public:
    Reputation(int reputationScore, int fansSupport);

    // Methods (stubs)
    void increaseReputation();
    void decreaseReputation();

    // Getters and Setters
    int getReputationScore() const;
};

// Class representing WeatherEffect
class WeatherEffect {
private:
    int staminaImpact;
    std::string fieldImpact;
    std::string weatherType;

public:
    WeatherEffect(int staminaImpact, std::string fieldImpact, std::string weatherType);

    // Methods (stubs)
    void applyWeatherEffect();

    // Getters and Setters
    int getStaminaImpact() const;
    std::string getFieldImpact() const;
};

#endif // GAME_OBJECTS_H
