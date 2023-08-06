import com_report as cr
from com_report import sign_decision

'''
몫 = q
제수=v
피제수=d
'''

def bin_add(a_arr,b_arr):
    for i in range(-1,-(len(a_arr)+1),-1):
        if i != -(len(a_arr)):
            if a_arr[i]+b_arr[i]==1 or a_arr[i]+b_arr[i]==0:
                a_arr[i]=a_arr[i]+b_arr[i]
            elif a_arr[i]+b_arr[i]==2:
                a_arr[i]=0
                a_arr[i-1]=a_arr[i-1]+1
            elif a_arr[i]+b_arr[i]==3:
                a_arr[i]=1
                a_arr[i-1]+=1
        else:
            if a_arr[i]+b_arr[i]==1 or a_arr[i]+b_arr[i]==0:
                a_arr[i]=a_arr[i]+b_arr[i]
            elif a_arr[i]+b_arr[i]==2:
                a_arr[i]=0
            elif a_arr[i]+b_arr[i]==3:
                a_arr[i]=1
    return a_arr

def bin_make_d(d,d_arr,d_sign,bit):
    while True:
        if d==0:
            d_arr.extend([0]*((bit)-len(d_arr)))
            d_arr.append(d_sign)        
            break
        else:
            d_arr.append(int(d%2))
            d=int(d/2)
    return d_arr

def bin_make_v(v,v_arr,v_sign,bit):
    while True:
        if v==0:
            v_arr.extend([0]*((bit)-len(v_arr)))
            v_arr.append(v_sign)        
            break
        else:
            v_arr.append(int(v%2))
            v=int(v/2)
    return v_arr

def non_restored_algorithm(d_arr,d_sign,v_arr,q,q_bit):
    result=""
    d_arr=d_arr[1:]
    v_arr=list([0]+v_arr[1:-1])
    v_arr_c=list(v_arr[:])
    if d_sign=="1":
        d_arr=cr.two_cp(cr.one_cp_2(d_arr,int(d_sign)),-1,int(d_sign))
    # print("피제수","".join(list(map(str,d_arr))))
    # print("제수,","".join(list(map(str,v_arr))))
    pz="".join(list(map(str,d_arr)))
    zs="".join(list(map(str,v_arr)))
    result=result+("초기피제수\t\t"+pz+"\n초기제수\t\t"+zs+"\n\n")
    for i in range(q_bit):
        if len(q)==0:
            v_arr_c=list(cr.two_cp(cr.one_cp_2(v_arr_c,1),-1,1))
            d_arr=bin_add(d_arr,v_arr_c)
            if d_arr[0]==1:
                q.append(0)
            else:
                q.append(1)

        elif q[-1]==0:
            d_arr=bin_add(d_arr,v_arr)
            if d_arr[0]==1:
                q.append(0)
            else:
                q.append(1)

        elif q[-1]==1:
            v_arr_c=list(cr.two_cp(cr.one_cp_2(list(v_arr),int(1)),-1,int(1)))
            d_arr=bin_add(d_arr,v_arr_c)
            if d_arr[0]==1:
                q.append(0)
            else:
                q.append(1)     
        
        # print("부분나머지","".join(list(map(str,d_arr))))
        # print("제수","".join(list(map(str,v_arr))))
        # print("몫","".join(list(map(str,q))))
        dan=str(i+1)
        result_a = "부분나머지\t\t"+str("".join(list(map(str,d_arr))))+"\n"
        result_b = "제수\t\t"+str("".join(list(map(str,v_arr))))+"\n"
        result_c = "몫\t\t"+str("".join(list(map(str,q))))+"\n\n"
        result=result+(dan+"단계\n"+result_a+result_b+result_c)
        v_arr=[0]+v_arr[0:-1] #시프트연산
    # print("나머지","".join(list(map(str,d_arr))))
    result=result+("나머지\t\t"+str("".join(list(map(str,d_arr)))))
    return result

def main2(q_bit,d,v):
    q=list()
    # q_bit=int(input("출력할 몫의 비트수를 입력하시오"))
    d_bit= q_bit*2
    # d=int(input("피제수를 입력하시오(10진수)"))
    # v=int(input("제수를 입력하시오(10진수)"))
    d_sign=str(sign_decision(d))
    v_sign=str(sign_decision(v))
    d=abs(d)
    v=abs(v)
    d_arr=list()
    v_arr=list()
    d_arr=bin_make_d(d,d_arr,d_sign,d_bit)
    v_arr=bin_make_v(v,v_arr,v_sign,q_bit)
    d_arr.reverse()
    v_arr.reverse()
    v_arr=v_arr+([0]*int(q_bit))
    
    # print(d_arr)
    # print(v_arr)
    result=non_restored_algorithm(d_arr,d_sign,v_arr,q,q_bit)
    return result
    
if __name__=="__main__":
    main2()