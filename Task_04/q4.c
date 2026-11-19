#include <stdio.h>
char grade_switch(int marks) {
    if(marks<0||marks>100) return '?';
    switch(marks/10) {
      case 10: case 9: return 'S';
      case 8: return 'A';
      case 7: return 'B';
      case 6: return 'C';
      case 5: return 'D';
      default: return 'F';
    }
}
char grade_ladder(int marks) {
    if(marks<0||marks>100) return '?';
    if(marks>=90) return 'S';
    else if(marks>=80) return 'A';
    else if(marks>=70) return 'B';
    else if(marks>=60) return 'C';
    else if(marks>=50) return 'D';
    return 'F';
}
const char *scholarship(char grade,int income) {
    if(income<0 || grade=='?') return "invalid";
    if(income<=200000 && (grade=='S'||grade=='A')) return "full";
    if(income<=400000 && (grade=='S'||grade=='A'||grade=='B')) return "partial";
    return "none";
}
int main(void) {
	int i;
    int tests[]={100,90,89,80,79,70,69,60,59,50,49,0,-1,101,95,83,-5};
for(i=0; i<sizeof(tests)/sizeof(tests[0]); i++)
       printf("%5d %6c %6c\n",tests[i],grade_ladder(tests[i]),grade_switch(tests[i]));
    printf("Scholarship example (95, income 150000): %s\n",scholarship(grade_switch(95),150000));
    return 0;
}
