class Interested_product:
      def __init__(self,brand,kind,price,link,gender):
        self.brand=brand
        self.kind=kind
        self.price=price #won
        self.link=link
        self.gender=gender
        self.next=next

      def __repr__(self):
        return f"product [brand: {self.brand}, kind:{self.kind}, price:{self.price},gender:{self.gender} ]"
  

class BMS:
    def __init__(self,db_size):
        self.db_size = db_size
        self.generate_db() #데이터베이스 생성

    def generate_db(self):
        self.item = ItemDB(self.db_size[0]) #링크드리스트
        self.user = UserDB(self.db_size[1]) # 2D배열
    
    def search(self, keyword):
        result = []
        
        curNode = self.item.pHead
        while curNode != None:
            if curNode.author == keyword:
                result.append(curNode)
            curNode = curNode.next
        for i in range(len(self.user.data)):
            if self.user.data[i][0]==keyword:
                result.append(self.user.data[i])
        return result
    
    def sort(self, order_by='asc'):
        N = len(self.user.data)-1
        for i in range(len(N-1)):
            for j in range(N-i-1):
                if order_by=='asc': # 오름차순
                    if self.user.data[j][1]>self.user.data[j+1][1]:
                        temp = self.user.data[j]
                        self.user.data[j]=self.user.data[j+1]
                        self.user.data[j+1]=temp
                else:
                    if self.user.data[j][1] < self.user.data[j+1][1]:
                        tmp = self.users.data[j]
                        self.users.data[j] = self.users.data[j+1]
                        self.users.data[j + 1] = tmp

    def delete(self,keyword):
        deleted = list()

        #item DB delet
        curNode = self.item.pHead
        prevNode = None
        while curNode != None:
            if curNode.author == keyword:
                self.item.size -=1
                if curNode == self.item.pHead:
                    self.item.pHead = curNode.next
                else:
                    prevNode.next = curNode.next
            prevNode = curNode
            curNode = curNode.next
        
        exixting_list = list()
        for user in self.user.data:
            if user[0] != keyword:
                exixting_list.append(user)
            else:
                deleted.append(user)
        self.users.data = exixting_list

        return len(deleted)
   
    def print_item_db(self, limit):  
      i = 0 
      p = limit
      curNode = self.item.pHead
      while i < p and curNode is not None:
        print(curNode)
        i += 1
        curNode = curNode.next
        
   
    def print_user_db(self, limit):
        for i in range(limit):
            print(self.user.data[i])



"!pip install names"
import names
import random
import string

# 링크드 리스트 기반 아이템 데이터베이스
class ItemDB:
    def __init__(self,nums):
        self.pHead = None
        self.pTail = None
        self.next = next
        self.size = 0
        self.nums = nums
        self.generate_db()

    #아이템 db생성
    def generate_db(self):
        all_kind=["Shoes","Pants",'outer',"Jacket"]
        for i in range(self.nums):
            brand = ''.join(random.choice(string.ascii_lowercase)for i in range(5))
            kind= "".join(random.choice(all_kind))
            price= random.randint(1000,1000000)
            link= ''.join(random.choice(string.ascii_lowercase)for i in range (5))
            gender = random.randint(1,50)
            if gender % 2 is 0:
                gender = "man"
            elif gender % 5 is 0:
                gender = "woman"
            else:
                gender = "man and woman"

            interested_product=Interested_product(brand,kind,price,link,gender)

            if self.pHead is None:
              self.pHead = interested_product
            else:
              self.pTail.next = interested_product
        
            self.pTail = interested_product
            self.size +=1

class UserDB:
    def __init__(self,nums):
        self.data=list()
        self.nums =nums
        self.generate_db()
    
    def generate_db(self):
        for i in range(self.nums):
            name = names.get_first_name(gender="female")
            age = random.randint(1,200)
            address = "".join(random.choice(string.ascii_lowercase)for i in range(6))
            user = [name,age,address]
            self.data.append(user)


bms = BMS([5,2])
bms.print_item_db(3)
bms.print_user_db(2)
