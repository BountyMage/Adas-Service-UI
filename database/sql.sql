-- CREATE TABLE ALADSSysStatus (
--     NOA_Status INTEGER ,
--     LateralControlStatus INTEGER
-- );

-- SELECT * FROM ALADSSysStatus;

-- drop table ALADSSysStatus

-- CREATE TABLE ALADSSysStatus (
--     Scene TEXT ,
--     NOA_Status INTEGER ,
--     LateralControlStatus INTEGER
-- );

-- INSERT INTO ALADSSysStatus (Scene, NOA_Status, LateralControlStatus)
-- VALUES ('Default', 0, 0);

-- alter table ALADSSysStatus
-- delete NOA_Status

-- SELECT * FROM ALADSSysStatus;

-- DROP TABLE ALADSSysStatus

-- SELECT * FROM ALADSSysStatus;

-- CREATE TABLE ALADSSysStatus (
--     Scene TEXT ,
--     '0' TEXT ,
--     '1' TEXT
-- );

-- INSERT INTO ALADSSysStatus (Scene, '0', '1')
-- VALUES ('Default', 0, 0);

-- update ALADSSysStatus set '0'=5
-- where Scene = 'passive'

-- SELECT Scene FROM ALADSSysStatus;

-- INSERT INTO ALADSSysStatus (Scene, '0', '1')
-- VALUES ('standby', '3', '3');

-- update ALADSSysStatus set 'Scene' = active
-- where '0' = '3';

-- delete from SLIFIHBCStatus
-- where Scene = 'tests';

-- SELECT * FROM SLIFIHBCStatus;

-- CREATE TABLE SLIFIHBCStatus (
--     Scene TEXT ,
--     '0' TEXT ,
--     '1' TEXT ,
--     '2' TEXT ,
--     '3' TEXT ,
--     '4' TEXT ,
--     '5' TEXT ,
--     '6' TEXT ,
--     '7' TEXT ,
--     '8' TEXT ,
--     '9' TEXT 
-- );

INSERT INTO SLIFIHBCStatus (Scene, '0', '1','2', '3','4', '5','6', '7','8', '9')
VALUES ('tests', '0', '1','2', '3','4', '5','6', '7','8', '9');

SELECT * FROM SLIFIHBCStatus;