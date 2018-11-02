def min_trains(arrivals, departures):
    arrivals.sort()
    departures.sort()

    #This first arrival must be before the first departure
    i = 1
    j = 0
    
    #We need at least 1 platform for first train
    num_platforms = 1
    max_platforms = 1

    # merge-sort like iteration thru both lists
    while i < len(arrivals) and j < len(departures):
        #next arrival before next depart
        if arrivals[i] < departures[j]:
            i += 1
            num_platforms += 1
        #next arrival after next depart
        elif arrivals[i] > departures[j]:
            j += 1
            num_platforms -= 1
        #next arrival same next depart
        elif arrivals[i] == departures[j]:
            i += 1
            j += 1
        
        #check see if new platform count greater
        if num_platforms > max_platforms:
            max_platforms = num_platforms
        
    return max_platforms
        


if __name__ == "__main__":
    arrivals = [900,  940, 950,  1100, 1500, 1800]
    departures = [910, 1200, 1120, 1130, 1900, 2000]

    
    print(min_trains(arrivals, departures))