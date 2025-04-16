
####### Loading the required packages #######
install.packages("pacman")
pacman::p_load(readxl, tidyverse, GGally, factoextra, 
               gridExtra, cluster, ggrepel, NbClust, ggplot2, dplyr, maps, RMySQL, grid)
options(digits=2)

################################################################################
theme_set(theme_bw())
theme_update(plot.title = element_text(hjust = 0.50,
                                       size = 14))



args <- commandArgs(trailingOnly = TRUE)
dataset_path <- args[1]
skiRes <- read.csv(dataset_path)


skiRes$Base.Elevation <- as.integer(skiRes$Base.Elevation)
skiRes$Skiable.Terrain <- as.integer(skiRes$Skiable.Terrain)
skiResClean <- skiRes[, -c(5, 9, 10, 12, 13, 14, 16, 20, 21, 23)]


ggplot(skiResClean, aes(x = Skiable.Terrain, y = Average.Snowfall, color = Pass, group = Pass)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(x = "Skiable Terrain (acres)", y = "Average Snowfall (inches)", 
       title = "Average Snowfall vs Skiable Terrain for Ikon and Epic Pass")


ggplot(skiResClean, aes(x = Pass, y = Average.Snowfall)) +
  geom_bar(stat = "identity")

ggplot(skiResClean, aes(x = Skiable.Terrain, y=Pass)) +
  geom_point() 



top_snowfall <- skiResClean %>% top_n(10, Average.Snowfall) %>% arrange(desc(Average.Snowfall)) %>%
  select(Location, Resort, Pass, Average.Snowfall)



oldest_mountain <- skiResClean %>% top_n(10, Years.Open) %>% arrange(desc(Years.Open)) %>%
  select(Location, Resort, Pass, Years.Open)


# Load shapefile for US states
us_map <- map_data("state")

ggplot(us_map, aes(x = long, y = lat, group = group)) +
  geom_polygon()

# Group the data by state and count the number of resorts in each state
resorts_by_state <- skiResClean %>%
  group_by(Location) %>%
  summarize(count = n())

# Merge data with latitude and longitude by state
state_coords <- map_data("state") %>% 
  group_by(region) %>% 
  summarize(long = mean(long), lat = mean(lat))

resorts_by_state_coords <- merge(resorts_by_state, state_coords, by.x = "Location", by.y = "region")
resorts_by_state_coords <- resorts_by_state_coords %>%
  mutate(group_id = row_number())



# Save the plot to a PDF file with a custom size and resolution
pdf("/Users/annikamore/Desktop/CLion/M3OEP-ahmore/skiGraphs.pdf", width = 8, height = 6)

ggplot() +
  geom_polygon(data=us_map, aes(x=long, y=lat, group=group), color="grey", fill="white") +
  geom_point(data = resorts_by_state_coords, aes(x = long, y = lat, color = count, size = count), alpha = 0.8) +
  scale_fill_gradient(low = "white", high = "red") +
  theme_void() +
  ggtitle("Number of Resorts in Each State")+
  theme(plot.title = element_text(hjust = 0.5))


# Assuming that your data frame is named "mydata" and you want to create a bar chart of "variable1" versus "variable2"
ggplot(data = top_snowfall, aes(x = reorder(Resort, -Average.Snowfall), y = Average.Snowfall, fill=Pass)) + 
  geom_bar(stat = "identity") +
  theme(axis.text.x = element_text(angle = 30, hjust = 1)) +
  labs(x = "Resort", y = "Average Seasonal Snowfall", title = "Resorts With The Highest Average Seasonal Snowfall ")


# Assuming that your data frame is named "mydata" and you want to create a bar chart of "variable1" versus "variable2"
ggplot(data = oldest_mountain, aes(x = reorder(Resort, -Years.Open), y = Years.Open, fill=Location)) + 
  geom_bar(stat = "identity") +
  theme(axis.text.x = element_text(angle = 30, hjust = 1)) +
  labs(x = "Resort", y = "Years Open", title = "Oldest Resorts on the Ikon and Epic Pass") 


ggplot(skiResClean, aes(x = Skiable.Terrain, y = Average.Snowfall, color = Pass, group = Pass)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(x = "Skiable Terrain (acres)", y = "Average Snowfall (inches)", 
       title = "Average Snowfall vs Skiable Terrain for Ikon and Epic Pass")

dev.off()



