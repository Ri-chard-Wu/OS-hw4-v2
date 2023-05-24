
import os




def verify_Fork(filename):
    print(f"verifying {filename} ...", end =" ")

    res_name = filename.split(".")[0]

    

    log_list = []
    cur_st = {"phr_st":{}, "n_res": -1}
    n_phr = 5

    with open(filename, "r") as f:

        # 1st line is meta data.
        for line in f: 
            n_res = int(line.strip())
            break


        for line in f:
            q = line.strip().split(", ")
            log_list.append({"time": q[0], "phr_id": int(q[1]), 
                            "state": q[2], "n_res": int(q[3])})

    # print("n_res: ", n_res)
    # for log in log_list:
    #     print(log)
    # exit()

    cur_st["n_res"] = n_res

    for i in range(n_phr):
        cur_st["phr_st"][i] = "RELEASED_RESOURCE"


    for log in log_list:

        next_st = log['state']
        phr_id = log['phr_id']

        if(next_st == "ACQUIRED_RESOURCE"):
            """
            // to-check: 
            // - cur st is not ACQUIRED_RESOURCE.
            // - cur n res is not 0.
            // - n res from log is consistent with next n res from python.
            1684909561672, 1, ACQUIRED_RESOURCE, 0
            """   
            
            if(cur_st["phr_st"][phr_id] == "ACQUIRED_RESOURCE"):
                print(f"phr {phr_id} acquired a {res_name} again before releasing it.")
                exit()
            
            cur_st["phr_st"][phr_id] = next_st

            if(cur_st["n_res"] == 0):
                print(f"phr {phr_id} acquired a {res_name} when there is no one.")
                exit()      

            cur_st["n_res"] -= 1          

            if(cur_st["n_res"] != log['n_res']):
                print(f"n_res not correct.")
                exit()    


        elif(next_st == "WAIT_ON_RESOURCE"):
            """
            // to-check: 
            // - cur st can only be RELEASED_RESOURCE. 
            // - cur n res is 0.      
            // - n res from log is consistent with next n res from python.
            1684909561672, 0, WAIT_ON_RESOURCE, 0
            """

            if(cur_st["phr_st"][phr_id] != "RELEASED_RESOURCE"):
                print(f'phr {phr_id} waits on {res_name} in {cur_st["phr_st"][phr_id]} state.')
                exit()

            cur_st["phr_st"][phr_id] = next_st

            if(cur_st["n_res"] != 0):
                print(f"phr {phr_id} waits on {res_name} when it is available.")
                exit()  

            if(cur_st["n_res"] != log['n_res']):
                print(f"n_res not correct.")
                exit()  

        elif(next_st == "RELEASED_RESOURCE"):
            """
            // to-check: 
            // - cur st can only be ACQUIRED_RESOURCE.
            // - n res from log is consistent with next n res from python.
            1684909565673, 1, RELEASED_RESOURCE, 1
            """

            if(cur_st["phr_st"][phr_id] != "ACQUIRED_RESOURCE"):
                print(f"phr {phr_id} released {res_name} before acquiring it.")
                exit()

            cur_st["phr_st"][phr_id] = next_st
            cur_st["n_res"] += 1          

            if(cur_st["n_res"] != log['n_res']):
                print(f"n_res not correct.")
                exit()  

        else:
            print("invalid state")
            exit()  

    print("ok")

fileName_dict = {"Fork":[], "Table": []}

for file in os.listdir("./"):
    if file.endswith(".log"):

        if("Fork" in file):
            fileName_dict["Fork"].append(file)
        elif("Table" in file):
            fileName_dict["Table"].append(file)
              

for filename in fileName_dict["Fork"]:
    verify_Fork(filename)



