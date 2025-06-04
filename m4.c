import pandas as pd


file_path = "/Users/syedabushrah/Desktop/training_dataset_CGPA.csv" 
df = pd.read_csv(file_path)


def find_s(data):
    
    attributes = data.iloc[:, :-1].values 
    target = data.iloc[:, -1].values      
   
    hypothesis = None
    
    for i, val in enumerate(target):
        if val.lower() == "yes":  
            hypothesis = attributes[i].copy()
            print(f"Initial Hypothesis (from first positive example): {hypothesis}\n")
            break

    if hypothesis is None:
        raise ValueError("No positive examples found in the dataset!")

    
    for i, val in enumerate(target):
        if val.lower() == "yes": 
            for j in range(len(hypothesis)):
                if hypothesis[j] != attributes[i][j]:
                    hypothesis[j] = "?"  
            print(f"Hypothesis after example {i+1}: {hypothesis}\n")

    return hypothesis


final_hypothesis = find_s(df)


print("Final Hypothesis:", final_hypothesis)
