CREATE TABLE offer (
  nr INT,
  product INT,
  producer INT,
  vendor INT,
  price DOUBLE PRECISION,
  validFrom DATETIME,
  validTo DATETIME,
  deliveryDays INT,
  offerWebpage VARCHAR(100),
  publisher INT,
  FOREIGN KEY (publisher) REFERENCES producer(nr),
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE person (
  nr INT,
  name VARCHAR(100),
  mbox_sha1sum VARCHAR(100),
  country VARCHAR(100),
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE producer (
  nr INT,
  label VARCHAR(100),
  comment VARCHAR(100),
  homepage VARCHAR(100),
  country VARCHAR(100),
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE product (
  nr INT,
  label VARCHAR(100),
  comment VARCHAR(100),
  producer INT,
  FOREIGN KEY (producer) REFERENCES producer(nr),
  propertyNum1 INT,
  propertyNum2 INT,
  propertyNum3 INT,
  propertyNum4 INT,
  propertyNum5 INT,
  propertyNum6 INT,
  propertyTex1 VARCHAR(100),
  propertyTex2 VARCHAR(100),
  propertyTex3 VARCHAR(100),
  propertyTex4 VARCHAR(100),
  propertyTex5 VARCHAR(100),
  propertyTex6 VARCHAR(100),
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);


CREATE TABLE productfeature (
  nr INT,
  label VARCHAR(100),
  comment VARCHAR(100),
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
  label VARCHAR(100),
  comment VARCHAR(100),
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
  title VARCHAR(100),
  text VARCHAR(100),
  language VARCHAR(100),
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
  label VARCHAR(100),
  comment VARCHAR(100),
  homepage VARCHAR(100),
  country VARCHAR(100),
  publisher INT,
  publishDate DATE,
  PRIMARY KEY (nr)
);

