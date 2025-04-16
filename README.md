# Ikon-Epic-Comparison

Name: Annika More

# Summary of Project

For this project, I read in a Kaggle dataset containing all of the ski resorts on both the Ikon pass and the Epic pass. The dataset includes variables like vertical drop, average snow, whether it is limited or unlimited, etc. for each resort. The user has the option of different comparisons they would like to make between the resorts on both passes. They are able to pick as many comparisons as they like. It will output the comparisons for each option to a separate file on your computer. Additionally, I added an option for the user to choose if they would like to look at visualizations of the data. If they choose this option, it will run R passing the csv file through the command line, and R will create graphs using ggplot. These graphs can help the user better understand differences in the resorts and passes if they don't want to look at tables. 

# Installation and Running Program

This program requires R studio and C++ to be installed on your computer. 

1. Clone the repository:

   ```bash
      git clone https://github.com/annikamore11/Ikon-Epic-Comparison.git
   ```

2. Navigate to project directory

   ```bash
   cd Ikon-Epic-Comparison
   ```

3. Find the Ikon-Epic-Comparison folder on your computer and copy the folder to your desktop or path of your choice.

4. Rename the copied folder Ikon-Epic-Comparison1

5. Since program must use absolute paths for the R file, if you plan to run the program you must go into the main.cpp in the Ikon-Epic-Comparison original folder and change line 102 from 

   ```bash
   string dataPath = "/Users/annikamore/Desktop/Ikon-Epic-Comparison1/skiresorts.csv";
   ```

   to your specific path to the copied folder. 

   Ex.

   ```bash
   string dataPath = "Users/your-name/Desktop/Ikon-Epic-Comparison1/skiresorts.csv";
   ```

6. You must also change line 181 from

   ```bash
   string command = "Rscript /Users/annikamore/Desktop/Ikon-Epic-Comparison1/skiGraphs.R " + dataset_path;
   ```

   to your specific path to the copied folder.

7. Lastly, you will have to go to skiGraphs.R in the original Ikon-Epic-Comparison original folder and change line 74 from

   ```bash
   pdf("/Users/annikamore/Desktop/Ikon-Epic-Comparison1/skiGraphs.pdf", width = 8, height = 6)
   ```

   to your specific path to the copied folder.

8. Build the project: 

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

9. Run the comparison program:

   ```bash
   ./M2OEP-ahmore
   ```

10. Indicate which comparisons you would like to view

# Results

To view the results from the comparisons picked, navigate to the Ikon-Epic-Comparison folder and click on the output files labeled by each option chosen. For example, if you chose option 1 then the file in the the folder would be named "Option 1/ General Comparison.csv".

If you chose option 5, the visual results will be stored in the "skiGraphs.pdf" file in the folder.

# Results Without Cloning the Repository

Below, I will include screenshots of the results obtained from the program without having to clone the repository. 

The program offers the user 5 comparison options. 

Comparison 1: A general comparison between the Ikon and Epic pass.

[option1.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/option1.png)

Comparison 2: The shortest and tallest ski resorts on the Ikon and Epic pass.

[option2.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/option2.png)

Comparison 3: Resorts that have been open the longest.

[option3.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/option3.png)

Comparison 4: Resorts with the most snowfall.

[option4.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/option4.png)

Comparison 5: Visualizations of The Data.

[visual 1.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/visual 1.png)

[visual2.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/visual2.png)

[visual3.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/visual3.png)

[visual4.png](https://github.com/annikamore11/Ikon-Epic-Comparison/blob/main/screenshots/visual4.png)

# Languages Used:

- R
- C++

# Citations

- geeksforgeeks.org
- stackoverflow.com
- Kaggle
