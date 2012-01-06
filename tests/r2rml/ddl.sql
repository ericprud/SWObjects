--
-- $Id$
CREATE TABLE DEPT (
    deptno INTEGER PRIMARY KEY, 
    dname VARCHAR(30), 
    loc VARCHAR(30));

-- INSERT INTO DEPT
--     (deptno,       dname,        loc) VALUES
--     (    10, "APPSERVER", "NEW YORK");

-- DEPT
-- | deptno | dname     | loc      |
-- | 10     | APPSERVER | NEW YORK |

CREATE TABLE EMP (
    empno INT PRIMARY KEY,
    ename VARCHAR(100),
    job VARCHAR(30),
    deptno INT,
    FOREIGN KEY (deptno) REFERENCES DEPT(deptno),
    etype VARCHAR(30) );

-- INSERT INTO EMP
--     (empno,   ename,     job, deptno,       etype) VALUES
--     ( 7369, "SMITH", "CLERK",     10, "PART_TIME");

-- EMP
-- | empno | ename | jobname | deptno | etype     |
-- | 7369  | SMITH | CLERK   | 10     | PART_TIME |

CREATE TABLE LIKES (
    id VARCHAR(4000),
    likeType VARCHAR(30),
    likeObj VARCHAR(200) );

-- INSERT INTO LIKES
--      (  id,   likeType,      likeObj) VALUES
--      (7369,  "Playing",     "Soccer");
-- INSERT INTO LIKES
--      (  id,   likeType,      likeObj) VALUES
--      (7369, "Watching", "Basketball");

-- LIKES
-- | id   | likeType | likeObj    |
-- | 7369 | Playing  | Soccer     |
-- | 7369 | Watching | Basketball |

