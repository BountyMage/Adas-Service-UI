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

-- delete from ALADSSysStatus
-- where Scene = 'standby';

