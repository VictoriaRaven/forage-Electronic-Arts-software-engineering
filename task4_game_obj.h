#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declarations for class relationships
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
    Athlete(std::string name, std::string position, std::vector<std::string> athleticStats) {
        this->name = name;
        this->position = position;
        this->athleticStats = athleticStats;
        reputation = nullptr;
        socialMediaAccount = nullptr;
    }

    void updateReputation();
    void createContent();
    void engageWithFollowers();
    void adaptToWeather(WeatherEffect* weatherEffect);

    // Setters and Getters
    void setReputation(Reputation* rep) { reputation = rep; }
    void setSocialMediaAccount(SocialMediaAccount* account) { socialMediaAccount = account; }
    void addFanInteraction(FanInteraction* interaction) { fanInteractions.push_back(interaction); }
    void addGame(Game* game) { games.push_back(game); }

    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
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
    SocialMediaAccount(double engagementRate, std::string accountType) {
        this->engagementRate = engagementRate;
        this->accountType = accountType;
    }

    void postContent(Post* post);
    void gainFollowers(int numFollowers);
    void loseFollowers(int numFollowers);
    void updateEngagement();

    // Setters and Getters
    void addPost(Post* post) { posts.push_back(post); }
    void addSponsorship(Sponsorship* sponsorship) { sponsorships.push_back(sponsorship); }
    void addFollower(Follower* follower) { followers.push_back(follower); }

    double getEngagementRate() const { return engagementRate; }
    std::string getAccountType() const { return accountType; }
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
    Post(std::string contentType, std::string postDate, int likes, int comments, int shares) {
        this->contentType = contentType;
        this->postDate = postDate;
        this->likes = likes;
        this->comments = comments;
        this->shares = shares;
    }

    void createPost();
    int getEngagement();
    void calculateReach();

    // Setters and Getters
    void addFanInteraction(FanInteraction* interaction) { fanInteractions.push_back(interaction); }
    std::string getContentType() const { return contentType; }
    std::string getPostDate() const { return postDate; }
};

// Class representing Follower
class Follower {
private:
    std::string name;
    std::string followerType;
    int engagementLevel;

public:
    Follower(std::string name, std::string followerType, int engagementLevel) {
        this->name = name;
        this->followerType = followerType;
        this->engagementLevel = engagementLevel;
    }

    void interactWithPost(Post* post);
    void increaseEngagement();

    // Setters and Getters
    std::string getName() const { return name; }
    std::string getFollowerType() const { return followerType; }
    int getEngagementLevel() const { return engagementLevel; }
};

// Class representing Sponsorship
class Sponsorship {
private:
    std::string brandName;
    double contractValue;
    int duration;
    std::string terms;

public:
    Sponsorship(std::string brandName, double contractValue, int duration, std::string terms) {
        this->brandName = brandName;
        this->contractValue = contractValue;
        this->duration = duration;
        this->terms = terms;
    }

    void signContract();
    void renewContract();

    // Setters and Getters
    std::string getBrandName() const { return brandName; }
    double getContractValue() const { return contractValue; }
};

// Class representing WeatherEvent
class WeatherEvent {
private:
    std::string weatherType;
    int severity;
    int duration;
    std::string impactOnGameplay;

public:
    WeatherEvent(std::string weatherType, int severity, int duration, std::string impactOnGameplay) {
        this->weatherType = weatherType;
        this->severity = severity;
        this->duration = duration;
        this->impactOnGameplay = impactOnGameplay;
    }

    void generateWeatherEvent();
    void applyImpactToGame(Game* game);

    // Setters and Getters
    std::string getWeatherType() const { return weatherType; }
    int getSeverity() const { return severity; }
};

// Class representing Game
class Game {
private:
    std::string gameTime;
    WeatherEvent* weather;
    std::vector<Team*> teamsInvolved;
    std::pair<int, int> score; // {team1_score, team2_score}

public:
    Game(std::string gameTime, WeatherEvent* weather, std::vector<Team*> teamsInvolved) {
        this->gameTime = gameTime;
        this->weather = weather;
        this->teamsInvolved = teamsInvolved;
    }

    void startGame();
    void pauseForWeather();
    void simulateWeatherImpact();
    void addTeam(Team* team) { teamsInvolved.push_back(team); }

    // Setters and Getters
    std::string getGameTime() const { return gameTime; }
    std::pair<int, int> getScore() const { return score; }
};

// Class representing Team
class Team {
private:
    std::string teamName;
    std::vector<std::string> teamStats;
    std::vector<Athlete*> players; // 1-to-many relationship with Athlete

public:
    Team(std::string teamName, std::vector<std::string> teamStats) {
        this->teamName = teamName;
        this->teamStats = teamStats;
    }

    void setLineup();
    void strategizeForWeather(WeatherEvent* weatherEvent);
    void addPlayer(Athlete* player) { players.push_back(player); }

    // Setters and Getters
    std::string getTeamName() const { return teamName; }
};

// Class representing Stadium
class Stadium {
private:
    std::string stadiumName;
    std::string location;
    std::string fieldCondition;

public:
    Stadium(std::string stadiumName, std::string location, std::string fieldCondition) {
        this->stadiumName = stadiumName;
        this->location = location;
        this->fieldCondition = fieldCondition;
    }

    void updateFieldCondition();

    // Setters and Getters
    std::string getStadiumName() const { return stadiumName; }
};

// Class representing FanInteraction
class FanInteraction {
private:
    std::string interactionType;
    std::string fanName;
    std::string message;

public:
    FanInteraction(std::string interactionType, std::string fanName, std::string message) {
        this->interactionType = interactionType;
        this->fanName = fanName;
        this->message = message;
    }

    void interact();

    // Setters and Getters
    std::string getFanName() const { return fanName; }
};

// Class representing EventImpact
class EventImpact {
private:
    std::string impactType;
    int severityLevel;
    Athlete* athleteImpact;

public:
    EventImpact(std::string impactType, int severityLevel, Athlete* athleteImpact) {
        this->impactType = impactType;
        this->severityLevel = severityLevel;
        this->athleteImpact = athleteImpact;
    }

    void applyImpact();

    // Setters and Getters
    std::string getImpactType() const { return impactType; }
};

// Class representing Reputation
class Reputation {
private:
    int reputationScore;
    int fansSupport;

public:
    Reputation(int reputationScore, int fansSupport) {
        this->reputationScore = reputationScore;
        this->fansSupport = fansSupport;
    }

    void increaseReputation();
    void decreaseReputation();

    // Setters and Getters
    int getReputationScore() const { return reputationScore; }
};

// Class representing WeatherEffect
class WeatherEffect {
private:
    int staminaImpact;
    std::string fieldImpact;
    std::string weatherType;

public:
    WeatherEffect(int staminaImpact, std::string fieldImpact, std::string weatherType) {
        this->staminaImpact = staminaImpact;
        this->fieldImpact = fieldImpact;
        this->weatherType = weatherType;
    }

    void applyWeatherEffect();

    // Setters and Getters
    int getStaminaImpact() const { return staminaImpact; }
    std::string getFieldImpact() const { return fieldImpact; }
};


#endif // GAME_OBJECTS_H
