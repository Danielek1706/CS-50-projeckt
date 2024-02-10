import csv
import sys
import random
import time

# Number of simulations to conduct
N = 1000

def main():
    # Checking the correctness of usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        for row in reader:
            team_name = row['team']
            team_rating = int(row['rating'])
            teams.append({'team': team_name, 'rating': team_rating})

    counts = {}

    start_time = time.time()  # Start measuring time

    # Simulating N tournaments and tracking the number of wins
    for i in range(N):
        winner_team = simulate_tournament(teams)
        if winner_team in counts:
            counts[winner_team] += 1
        else:
            counts[winner_team] = 1

    end_time = time.time()  # End measuring time
    elapsed_time = end_time - start_time

    # Printing the chances of each team winning, according to the simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    print(f"Simulation duration: {elapsed_time:.3f} seconds")

def simulate_game(team1, team2):
    """Simulating a game. Returns True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

def simulate_round(teams):
    """Simulating a round. Returns a list of winning teams."""
    winners = []

    # Simulating games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners

def simulate_tournament(teams):
    """Simulating a tournament. Returns the name of the winning team."""
    # Simulating tournament rounds until only one team remains.
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]

if __name__ == "__main__":
    main()
