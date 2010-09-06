CREATE TABLE offer (
  nr INT,
  product INT,
  producer INT,
  vendor INT,
  price DOUBLE,
  validFrom DATETIME,
  validTo DATETIME,
  deliveryDays INT,
  offerWebpage STRING,
  publisher INT,
  FOREIGN KEY (publisher) REFERENCES producer(nr),
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE person (
  nr INT,
  name STRING,
  mbox_sha1sum STRING,
  country STRING,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE producer (
  nr INT,
  label STRING,
  comment STRING,
  homepage STRING,
  country STRING,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE product (
  nr INT,
  label STRING,
  comment STRING,
  producer INT,
  FOREIGN KEY (producer) REFERENCES producer(nr),
  propertyNum1 INT,
  propertyNum2 INT,
  propertyNum3 INT,
  propertyNum4 INT,
  propertyNum5 INT,
  propertyNum6 INT,
  propertyTex1 STRING,
  propertyTex2 STRING,
  propertyTex3 STRING,
  propertyTex4 STRING,
  propertyTex5 STRING,
  propertyTex6 STRING,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE productfeature (
  nr INT,
  label STRING,
  comment STRING,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE productfeatureproduct (
  product INT,
  productFeature INT,
  PRIMARY KEY (product,productFeature)
);


CREATE TABLE producttype (
  nr INT,
  label STRING,
  comment STRING,
  parent INT,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE producttypeproduct (
  product INT,
  productType INT,
  PRIMARY KEY (product,productType)
);


CREATE TABLE review (
  nr INT,
  product INT,
  producer INT,
  person INT,
  reviewDate DATETIME,
  title STRING,
  text STRING,
  language STRING,
  rating1 INT,
  rating2 INT,
  rating3 INT,
  rating4 INT,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE vendor (
  nr INT,
  label STRING,
  comment STRING,
  homepage STRING,
  country STRING,
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);

