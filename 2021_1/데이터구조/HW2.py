'''
  웹툰(Webtoon) 클래스
  ** linked list를 위한 next 링크를 만듬
'''
class Webtoon:
   def __init__(self, title, author, published_date, rating, img):
      self.title = title # 문자열
      self.author = author # 문자열
      self.published_date = published_date # 문자열
      self.rating = rating  # float
      self.img = img # 문자열
      self.next = None # 이동 레퍼런스
   
   # print 하는 내용을 아래와 같은 형태로 변경할 수 있음.
   # w = Webtoon(...) 
   # print(w) 시 아래와 같은 내용으로 출력
   def __repr__(self):
      return f"WEBTOON [title: {self.title}, author:{self.author}, published_date: .... ]"
'''
  Bigdata Management System ADT 
  BMS ADT
'''
class BMS:
  '''
    BMS 생성자
    db_size: 아이템[0], 사용자 DB[1]를 생성함 , LIST 타입
  '''
  def __init__(self, db_size):
    self.db_size = db_size
    self.generate_db() # 데이터 베이스 생성

  # 요구사항 1과 2
  # 링크드 리스트 기반 ItemDB
  # 2d 리스트 기반 userDB
  '''
    데이터 생성
  '''
  def generate_db(self):
    self.items = ItemDB(self.db_size[0]) # 링크드 리스트
    self.users = UserDB(self.db_size[1]) # 2D 배열

  '''
    데이터 검색
    keyword: 검색할 키워드
  '''
  def search(self, keyword):
    # 결과에는 데이터형 관계없이 추가가가능
    results = []

    # 링크드 리스트 탐색
    curNode = self.items.pHead
    while curNode is not None:
      if curNode.author == keyword:
        results.append(curNode)
      ### 검색 조건
      curNode = curNode.next

    # 사용자DB 탐색
    for i in range(len(self.users.data)):
      # 사용자 이름과 keyword가 매칭될때
      if self.users.data[i][0] == keyword: 
        results.append(self.users.data[i])
    
    return results

  '''
    데이터 정렬 (사용자DB만)
    버블 정렬을 사용함
    order_by: asc 오름차, 그외 내림차
  '''
  def sort(self, order_by='asc'):
    # 버블정렬을 사용함
    N = len(self.users.data)-1
    for i in range( N -1 ):
      for j in range( N - i - 1 ):
          if order_by == 'asc': # 오름차순
              if self.users.data[j][1] > self.users.data[j+1][1] :
                 tmp = self.users.data[j]
                 self.users.data[j] = self.users.data[j+1]
                 self.users.data[j + 1] = tmp 
          else: # 내림차순
              if self.users.data[j][1] < self.users.data[j+1][1] :
                 tmp = self.users.data[j]
                 self.users.data[j] = self.users.data[j+1]
                 self.users.data[j + 1] = tmp 

  '''
    데이터 삭제 (아이템DB, 사용자DB 모두)
    keyword: 삭제할 키워드
  '''
  def delete(self, keyword):
    # 삭제할 내용에 대해 저장
    deleted = list()
    
    # 아이템DB에서 keyword에 매칭되는 author 를 찾아 해당 노드 삭제
    curNode = self.items.pHead
    prevNode = None
    while curNode is not None:
      # keyword에 매칭되는 author 찾았다면
      if curNode.author == keyword:
        self.items.size -= 1
        if curNode is self.items.pHead:
           self.items.pHead = curNode.next
        else:
          prevNode.next = curNode.next
      # 다음 노드로 이동        
      prevNode = curNode
      curNode = curNode.next
        
    # 사용자DB로부터 keyword에 매칭되는 user 이름를 찾아 제거
    # ** 제거하는 경우, index크기가 변화되서 에러가 발생되기 때문에 
    # ** 매칭되는 것을 제외하고 existing_list에 복사한뒤, 새로운 사용자DB를 생성
    # ** 더 좋은 방법이 존재할 수 있음.
    existing_list = list()
    for user in self.users.data:
      if user[0] != keyword:
          existing_list.append(user)
      else:
          deleted.append(user)
    self.users.data = existing_list

    return len(deleted)
  
  '''
    ItemDB 데이터베이스 내용 출력
    limit: 최대 출력할 갯수
  '''
  def print_item_db(self, limit):  
    i = 0 
    p = limit
    curNode = self.items.pHead
    while i < p and curNode is not None:
      print(curNode)
      i += 1
      curNode = curNode.next
  
  '''
    UserDB 데이터베이스 내용 출력
    limit: 최대 출력할 갯수
  '''
  def print_user_db(self, limit):
    for i in range(limit):
      print(self.users.data[i])
      

import numpy as np
monthly_days = np.arange(0, 30)
base_date = np.datetime64('2021-03-01')
# names라는 라이브러리 인스톨
"!pip install names"
import names
import random
import string

# 요구사항 2: 링크드 리스트 기반의 아이템 데이터베이스
class ItemDB: 
  '''
    아이템DB 생성자
    nums: 생성할 레코드의 수
  '''
  def __init__(self, nums):
    self.pHead = None
    self.pTail = None
    self.size = 0
    self.nums = nums
    self.generate_db()

  '''
    사용자DB를 생성
  '''
  def generate_db(self):
    # 랜덤 데이터 와 함께 생성
    for i in range(self.nums):
      # 랜덤 데이터와 함께 인스턴스 생성
      title = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
      author = names.get_first_name(gender='female')
      published_date = base_date + np.random.choice(monthly_days)
      rating = round(random.uniform(1, 10), 2)
      img = ''.join(random.choice(string.ascii_lowercase) for i in range(5))

      # 인스턴스 생성
      webtoon = Webtoon(title, author, published_date, rating, img)

      # 링크드 리스 트 데이터 추가
      if self.pHead is None:
         self.pHead = webtoon
      else: # 한개 이상이 있는 경우
         self.pTail.next = webtoon

      self.pTail = webtoon
      self.size += 1


# 2d리스트 기반 사용자 데이터베이스
class UserDB: # 리스트를 상속(inheritance)받아 바로 리스트 접근가능
    '''
      사용자DB 생성자(초기화)
      nums: 생성할 레코드의 수
    '''
    def __init__(self, nums):
      self.data = list() # 이와 같이 별도의 리스트를 생성해도 무관
      self.nums = nums
      self.generate_db()
     
    '''
      사용자DB 생성
    '''
     # 데이터베이스 생성
    def generate_db(self):              
       for i in range(self.nums):
        # 랜덤데이터 생성
        name = names.get_first_name(gender='female')
        age = random.randint(1, 1000)
        favorite = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
        user = [name,age,favorite]

        self.data.append(user) # 데이터 추가