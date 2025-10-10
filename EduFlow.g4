grammar Eduflow;


program: EOF;

scheduleBlock: '{' session (',' session)* '}';
session: DAY ':' TIME '-' TIME;
idList: '[' (ID (',' ID)*)? ']';
expression: term (LOGICAL_OP term)*;
term: ID | ATTR_ID OPERATOR value | '(' expression? ')';
value: STRING | INT | FLOAT;


DEFINE: 'define';
COURSE: 'course';
RULE: 'rule';
WORKFLOW: 'workflow';
SIMULATE: 'simulate';
STAGE: 'stage';
SET: 'set';
WHERE: 'where';
USING: 'using';
FOR: 'for';
STUDENT: 'student';
ATTEMPT: 'attempt';
ENROLL: 'enroll';
IN: 'in';

DAY    : 'MON' | 'TUE' | 'WED' | 'THU' | 'FRI' | 'SAT';
LOGICAL_OP: 'AND' | 'OR';
OPERATOR: '==' | '!=' | '>' | '<' | '>=' | '<=';


ID: [a-zA-Z_][a-zA-Z0-9_]*;
ATTR_ID: [a-zA-Z_]+ '.' [a-zA-Z_]+;
STRING : '"' (~["])* '"' ;
INT    : [0-9]+ ;
FLOAT  : [0-9]+ '.' [0-9]+;
TIME   : INT ':' INT;

WS: [ \t\r\n]+ -> skip ;
COMMENT: '//' ~[\r\n]* -> skip;