#include <iostream>
#include <vector>
using namespace std;

int totalWater = 0;
struct bucket{
  int size;
  int contents;
  bool empty;
  bool full;
  bucket(int sz, int con){
    size = sz;
    contents = con;
  }
  void adjust(){
    if(contents == 0){
      empty = true;
    }
    else{
      empty = false;
    }
    if(size == contents){
      full = true;
    }
    else{
      full = false;
    }
  }
};

struct store{
  int a;
  int b;
  int c;
  store(int x, int y, int z){
    a = x;
    b = y;
    c = z;
  }
};

bool dup(vector <store> &past, int a, int b, int c){
  for(int i = 0; i < past.size(); i++){
    if(past[i].a == a && past[i].b == b && past[i].c == c){
      //cout << "It's a dup!!!!" << endl;
      return true;
    }
  }
  return false;
}

void mkRecord(vector <store> &past, int x, int y, int z){
  store a(x,y,z);
  past.push_back(a);
}


bool check(bucket &a, bucket &b, bucket &c){
  if(b.contents == 2 || c.contents == 2){
    cout << "Done! Contents of a,b,c -> "<< a.contents << " " << b.contents << " " << c.contents << endl;
    return true;
  }
  else{
    return false;
  }
}

bool interPour(bucket &x, bucket &y, int &count){
  if(! x.empty && ! y.full){
    int extraSpace = y.size - y.contents;
    if(x.contents > extraSpace){
      //cout << "Poured " << x.size << ": " << x.contents << " into " << y.size << ": " << y.contents << endl;
      x.contents -= extraSpace;
      y.contents += extraSpace;
      x.adjust();
      y.adjust();
      totalWater += extraSpace;
      count++;
      return true;
    }
    else{
      //cout << "Poured " << x.size << ": " << x.contents << " into " << y.size << ": " << y.contents << endl;
      y.contents += x.contents;
      totalWater += x.contents;
      x.contents = 0;
      x.adjust();
      y.adjust();
      count++;
      return true;
    }
  }
  else{
    //cout << "Pour is empty or full" << endl;
    x.adjust();
    y.adjust();
    return false;
  }
  x.adjust();
  y.adjust();
}

bool pour(bucket &a, bucket &b, bucket &c, int x, int y, int &count){
  bool rt = false;
  int aa = a.contents;
  int bb = b.contents;
  int cc = c.contents;
  if(x == 0 && y == 1){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(a,b,count);
  }
  if(x == 0 && y == 2){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(a,c,count);
  }
  if(x == 1 && y == 2){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(b,c,count);
  }
  if(x == 1 && y == 0){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(b,a,count);
  }
  if(x == 2 && y == 0){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(c,a,count);
  }
  if(x == 2 && y == 1){
    cout << a.contents << " " << b.contents << " " << c.contents << endl;
    rt = interPour(c,b,count);
  }
  //cout << "Your tried to pour " << x << " into " << y << endl;
  return rt;
}

bool findTwo(bucket &a, bucket &b, bucket &c, vector <store> &past, int &count){
  bool rec;
  if(check(a,b,c) == true){
    return true;
  }
  bool duplicate;

  //Mod two to work quicker towards 2 in buckets.
  cout << "Mod checks" << endl;
  if((a.contents + b.contents) % 7 == 2){
    if(a.contents < b.contents){
      rec = pour(a, b, c, 0, 1,count);//a into b
      if(check(a,b,c) == true){
	return true;
      }
    }
    else{
      rec = pour(a, b, c, 1, 0,count);// b into a
      if(check(a,b,c) == true){
	return true;
      }
    }
  }
  cout << "After 1st mod check" << endl;
  if((b.contents + c.contents) % 7 == 2){
    if(b.contents < c.contents){
      rec = pour(a, b, c, 1, 2,count);// b into c
      if(check(a,b,c) == true){
	return true;
      }
    }
    else{
      rec = pour(a, b, c, 2, 1,count);// c into b
      if(check(a,b,c) == true){
	return true;
      }
    }
  }
  cout << "After 2nd mod check" << endl;
  if((a.contents + c.contents) % 7 == 2){
    if(a.contents < c.contents){
      rec = pour(a, b, c, 0, 2,count); // a into c
      if(check(a,b,c) == true){
	return true;
      }
    }
    else{
      rec = pour(a, b, c, 2, 0,count); // c into a
      if(check(a,b,c) == true){
	return true;
      }
    }
  }
  cout << "Completed mod checks" << endl;
  //Check past iterations for duplicate



  while(check(a,b,c) == false){
    if(count > 6){
      a.contents = 0;
      b.contents = 7;
      c.contents = 4;
      count = 0;
      past.clear();
      totalWater = 0;
    }
    if(! dup(past, a.contents, b.contents, c.contents)){
      mkRecord(past,a.contents,b.contents,c.contents);
    }
    int i = rand() % 3;
    int j = rand() % 3;
    rec = pour(a, b, c, i, j, count);
  }
  mkRecord(past,a.contents,b.contents,c.contents);
  return true;
}

int main(){
  srand ( time(NULL) );
  bool done;
  bucket a(10,0);
  a.adjust();
  bucket b(7,7);
  b.adjust();
  bucket c(4,4);
  c.adjust();
  int count = 0;
  vector <store> past;
  done = findTwo(a, b, c, past, count);
  cout << a.contents << " " << b.contents << " " << c.contents << endl;
  cout << "Total pours = " << count << endl;
  for(int i = 0; i < past.size(); i++){
    cout << past[i].a << " " << past[i].b << " " << past[i].c << endl;
    for(int j = 0; j < i+1; j++){
      cout << "  ";
    }
  }
  cout << endl;
  cout << "Total Water poured: " << totalWater << endl;
  return 0;
}
