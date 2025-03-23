#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>  // smart pointers

// Note: this is a revised version of my header file so that it matches with the answer key format
// I ONLY included this as I wasn't sure my version would be acceptable, but I turned in that ver anyway.

// Interface for Social Media Strategy
class SocialMediaStrategy {
public:
    virtual void postContent() = 0;
    virtual void updateEngagement() = 0;
};

// Implementation of different social media strategies
class PostContentStrategy : public SocialMediaStrategy {
public:
    void postContent() override;
    void updateEngagement() override;
};

class GainFollowersStrategy : public SocialMediaStrategy {
public:
    void postContent() override;
    void updateEngagement() override;
};

class LoseFollowersStrategy : public SocialMediaStrategy {
public:
    void postContent() override;
    void updateEngagement() override;
};

// Interface for Athlete Strategy
class AthleteStrategy {
public:
    virtual void performAction() = 0;
};

// Various actions athletes can perform
class CreateContent : public AthleteStrategy {
public:
    void performAction() override;
};

class EngageWithFollowers : public AthleteStrategy {
public:
    void performAction() override;
};

class UpdateReputation : public AthleteStrategy {
public:
    void performAction() override;
};

// Class representing a SocialMediaAccount
class SocialMediaAccount {
private:
    double engagementRate;
    std::string accountType;
    std::vector<std::unique_ptr<SocialMediaStrategy>> strategies;  // Using smart pointers

public:
    SocialMediaAccount(double engagementRate, std::string accountType)
        : engagementRate(engagementRate), accountType(std::move(accountType)) {
    }

    void addStrategy(std::unique_ptr<SocialMediaStrategy> strategy) {
        strategies.push_back(std::move(strategy));
    }

    void executeStrategies() {
        for (auto& strategy : strategies) {
            strategy->postContent();
            strategy->updateEngagement();
        }
    }

    double getEngagementRate() const { return engagementRate; }
    std::string getAccountType() const { return accountType; }
};

// Class representing an Athlete
class Athlete {
private:
    std::string name;
    std::string position;
    std::vector<std::string> athleticStats;  // Example stats like {"speed: 9", "strength: 8"}
    std::shared_ptr<SocialMediaAccount> socialMediaAccount; // Shared pointer to SocialMediaAccount
    std::vector<std::unique_ptr<AthleteStrategy>> strategies;  // Using smart pointers

public:
    Athlete(std::string name, std::string position, std::vector<std::string> athleticStats)
        : name(std::move(name)), position(std::move(position)), athleticStats(std::move(athleticStats)) {
    }

    void addStrategy(std::unique_ptr<AthleteStrategy> strategy) {
        strategies.push_back(std::move(strategy));
    }

    void performActions() {
        for (auto& strategy : strategies) {
            strategy->performAction();
        }
    }

    void setSocialMediaAccount(std::shared_ptr<SocialMediaAccount> account) {
        socialMediaAccount = account;
    }

    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
};

// Interface for Weather Impact
class WeatherImpact {
public:
    virtual void applyWeatherImpact() = 0;
};

// Concrete WeatherImpact classes
class RainyWeather : public WeatherImpact {
public:
    void applyWeatherImpact() override;
};

class SunnyWeather : public WeatherImpact {
public:
    void applyWeatherImpact() override;
};

// Class representing a Game
class Game {
private:
    std::string gameTime;
    std::vector<std::shared_ptr<Athlete>> athletes;  // Using shared pointers to handle athletes' ownership
    std::unique_ptr<WeatherImpact> weatherImpact;  // Using smart pointers

public:
    Game(std::string gameTime) : gameTime(std::move(gameTime)) {}

    void setWeatherImpact(std::unique_ptr<WeatherImpact> impact) {
        weatherImpact = std::move(impact);
    }

    void startGame() {
        // Start game logic
    }

    void applyWeatherImpact() {
        weatherImpact->applyWeatherImpact();
    }

    void addAthlete(std::shared_ptr<Athlete> athlete) {
        athletes.push_back(athlete);
    }

    std::string getGameTime() const { return gameTime; }
};

// Interface for Sponsorship Strategy
class SponsorshipStrategy {
public:
    virtual void signContract() = 0;
    virtual void renewContract() = 0;
};

// Concrete Sponsorship Strategies
class CorporateSponsorship : public SponsorshipStrategy {
public:
    void signContract() override;
    void renewContract() override;
};

class LocalSponsorship : public SponsorshipStrategy {
public:
    void signContract() override;
    void renewContract() override;
};

// Class representing a Sponsorship
class Sponsorship {
private:
    std::string brandName;
    double contractValue;
    int duration;
    std::unique_ptr<SponsorshipStrategy> sponsorshipStrategy;

public:
    Sponsorship(std::string brandName, double contractValue, int duration)
        : brandName(std::move(brandName)), contractValue(contractValue), duration(duration) {
    }

    void setSponsorshipStrategy(std::unique_ptr<SponsorshipStrategy> strategy) {
        sponsorshipStrategy = std::move(strategy);
    }

    void executeSponsorshipStrategy() {
        sponsorshipStrategy->signContract();
        sponsorshipStrategy->renewContract();
    }

    std::string getBrandName() const { return brandName; }
    double getContractValue() const { return contractValue; }
};

#endif // GAME_OBJECTS_H
