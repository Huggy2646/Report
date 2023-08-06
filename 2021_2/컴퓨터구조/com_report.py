"""
<3>
부가점 관련 기능 설명 찾기
사용법 : Ctrl+F를 사용하여 찾고싶은 부가기능 설명 숫자를 "<",">" 사이에 넣어 검색하시면 됩니다.
    ex) "흐음... 어디보자 양수, 음수 모두에 대해 세가지 표현이 가능한 경우를 찾아볼까?"
         -------------------------------
        ㅣ            _검색창_          ㅣ
        ㅣ______________________________|
        ㅣ              <1>             |
         --------------------------------

    1. 양수, 음수 모두에 대해 세가지 표현이 가능한 경우
    2. 8bit, 16bit, 32bit, 64bit을 전부 가능하게 만들기
    3. 부가점 관련 기능 구현 시 프로그램 내에 주석이나 별도 텍스트 파일에 표기하여 제출

"""



'''

sign_decision(string)
    사용자가 입력한 값에 따라 부호가 결정이 됩니다.             
    특수한 값 -0,+0을 구분하기 위해 input단계에서 정해지는 type 즉, string type으로 인자를 받습니다.         #<1>   
'''
def sign_decision(a):
    if int(a)<0:
        return 1
    elif a=="-0":
        return 1
    elif a=="+0" or a=="0":
        return 0
    else:
        return 0


'''
excha(Integer)
    1의 보수를 생성할 때 보수를 취해주기 위한 함수입니다.
'''
def excha(x):
    if x==0:
        return 1
    else:
        return 0


'''
one_cp(List, Integer)
    1의 보수를 생성하는 함수입니다.
    List 매개변수는 1의 보수를 생성하고 싶은 2진수들이 1bit단위로 구분된 List를 인자로 받습니다.
        ex) 8bit의 2의 2진수 List => [0,0,0,0,0,0,1,0]
            16bit의 2의 2진수 List => [1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0]
    Integer 매개변수는 부호값이 들어갑니다.

    함수 내부의 arr[1:]를 하는 이유는 2진수 List의 제일 앞의 value는 부호비트이기 때문에 부호비트를 제외한 실직적으로 숫자데이터를 표현하는 부분을 연산이기 위함입니다.

    또한, 조건문을 사용하여 부호비트가 '-'이면 연산을 수행하고 '+'이면 값이 같으므로 인자로 받은 List를 그대로 return를 해 줍니다.                   #<1>
'''
def one_cp(arr,a_sign):
    
    if a_sign==1:
        arr[1:]=list(map(lambda x:excha(x),arr[1:]))
        return arr
    else:
        return arr
    
def one_cp_2(arr,a_sign):
    
    if a_sign==1:
        arr[:]=list(map(lambda x:excha(x),arr[:]))
        return arr
    else:
        return arr
'''
(Reverse_Index of List)

two_cp(List,Integer, Integer)
    2의 보수를 생성하는 함수입니다.
    List로 2의 보수를 생성하고 싶은 2진수들의 "1의 보수"가 1bit단위로 구분된 List를 인자로 받습니다.
    첫번째 Integer은 recursion을 사용하여 +1을 할 때 사용되어지는 list의 index로 제일 마지막 값의 index의 값 -1이 고정으로 들어갑니다.
    두번째 Integer은 부호값이 들어갑니다.

    조건문을 사용하여 부호가 "1"인 즉, 음수인 데이터만 2의 보수를 생성하게 만들었습니다.                  #<1>


    2진법에서 1,0 2개의 숫자로만 표현 가능 하므로 1+1을 하면 그 자리는 0이 되고, 한 칸앞에 있는 데이터에 +1을 해주는 시스템을 가지고 있습니다.
    
    이러한 성질의 이용하여 아래와 같이 조건문을 생성하였습니다.
        1) 첫번째 Integer로 받은 인자를 사용하여 list의 마지막 value값을 가져와 1 or 0을 판단합니다.
        2-1) 만약 1이라면 그 자리는 0으로 대체되고 recursion을 사용하여 첫번째 Integer의 값에 -1을 더함으로써 Index을 값이 앞으로 나아갑니다.
        2-2) 만약 0이라면 그 자리는 1로 대체되고 arr이 return되어집니다.

    만약 8bit의 -0이면 1의 보수의 list의 형태는 [1,1,1,1,1,1,1,1]이 되고,                                                                  #<1>
        여러번의 recursion을 거쳐 생성된 첫번째 Integer의 값이 list의 길이보다 크므로 "-0이라서 값이 없습니다"라고 return 해줍니다.            #<1>
'''
def two_cp(arr,i,a_sign):
    if a_sign==1:
        if len(arr[1:])<i*(-1): # -0일때
            return "-0이라서 값이 없습니다"
        else:
            if arr[i] == 1:
                arr[i]=0
                return two_cp(arr,i-1,a_sign)
            else:
                arr[i]=1
                return arr
    else:
        return arr
'''
<1>
input을 사용하여 1의 보수와 2의 보수를 만들 숫자를 입력받습니다. 이때 Stirng으로 입력을 받게 되는데 int형으로 바꾸지 않는 이유는 -0과 +0을 입력하고 int형으로 바꾸게 되면 부호가 없어진 0으로 되기 때문입니다.
    부호를 판단하고 정수로 바꾸어 주는 과정을 거치는데 이때 앞에서 받은 값이 숫자로 된 string이 아닌 문자로 된 string이 라면 ValueErrer가 뜨게 됩니다. 이것을 이용하여 예외처리를 할 수 있는 tyr exception문을
    사용하여 ValueErrer가 발생면 return main()을 사용하여 다시 프로그램이 돌아가도록 설계하였습니다.
<2>
원하는 bit크기를 정하기 위해 input을 사용하여 bit의 숫자만 입력 받습니다. 입력 받은 bit는 나중에 생성될 2진수 list의 length를 제한하는 역할을 합니다.

<2>
Line124같은 경우 2진수로 바꾼 값들이 1bit단위로 구분된 list의 크기는 원하는 bit크기가 아닐 수도 있습니다. 그래서 부호비트확장을 위하여 생성된 코드입니다.
    나중에 생성된 부호비트를 넣기위해 원하는 bit크기보다 1이 작은 list를 생성해야합니다. 부호비트 확장을 하게 되면 확장을 한 만큼 0이 추가 되어야 합니다.
    그러므로 [0]을 만들어 원하는 bit의 크기에서 현재까지 생셩된 d2진수 list length를 빼준 값을 list의 곱연산을 하고 extend함수를 이용하여 확장을 시켜줍니다.
    그 후 앞에서 생성한 부호비트를 append함수를 사용하여 추가한 다음 reverse를 사용하여 왁벽한 2진수로 만들어 줍니다.
    
    예를들어 8bit의 10진수 2를 만들자고 한다면,
        10진수인 2를 2진수로 바꾸어 줍니다. 이때 list는 [0,1]이 됩니다. 그리고 Line124의 코드로 인해 [0]*5가 되고, 이것은 [0,0,0,0,0]가 됩니다.
        그 후 extend를 해주면 list의 형태는 [0,1,0,0,0,0,0]이 되고 , 부호비트를 append하면[0,1,0,0,0,0,0,0], reverse를 하면 [0,0,0,0,0,0,1,0]이 됩니다.
<2>
Line141같은 경우 원하는 bit크기보다 앞에서 생성한 list의 크기가 크면 사실상 표현가능한 범위를 벗어났다는 의미입니다.
    if 문을 이용하여 만약 넘어갔다면 값이 넘어갔다고 출력해줍니다.
'''
def main():
    try:
        print("Ctrl+z를 입력하면 프로그램이 종료됩니다.")
        arr=list()
        a=input("10진수 정수를 입력하세요:")
        a_sign=sign_decision(a)
        bit_list=[8,16,32,64]
        bit=int(input("bit크기를 입력하시오(8bit, 16bit, 32bit, 64bit / 숫자만 입력):"))
        if bit not in bit_list:
            print(bit,"bit는 제공되지 않습니다.")
            print("\n")
            return main()
        a=int(a)
        while True:
            if a==0:
                arr.extend([0]*((bit-1)-len(arr)))
                arr.append(a_sign)        
                break
            else:
                arr.append(int(a%2))
                a=int(a/2)


        if bit == len(arr):
            arr.reverse()
            print("부호와 크기형태 출력","".join(map(str,arr)))
            print("1의 보수:","".join(map(str,one_cp(arr,a_sign))))
            arr=two_cp(arr,-1,a_sign)
            if arr !=0:
                print("2의 보수:","".join(map(str,arr)))
            else:
                print(arr)
            print("\n")
        else:
            print("표현가능한 범위를 넘어갔습니다.")
            print("\n")

    except ValueError:
        print("값이 잘못 입력되었습니다.")
        print("\n")
        return main()

'''
무한loop를 사용하여 main()을 계속 돌려주는 동시에 EOFError예외처리를 사용하여 "Crtl+z"를 입력받게 되면 무한loop를 탈출 하도록 설계하였습니다.
'''

if __name__=="__main__":
    while True:
        try:
            main()
        except EOFError:
            break