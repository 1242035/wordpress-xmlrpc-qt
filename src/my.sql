/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

DROP TABLE IF EXISTS "cap";
CREATE TABLE "cap" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "manage_terms" TEXT, "edit_terms" TEXT, "delete_terms" TEXT, "assign_terms" TEXT);
DROP TABLE IF EXISTS "categories";
CREATE TABLE "categories" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "categoryid" TEXT UNIQUE, "parentid" TEXT, "categoryname" TEXT, "categorydescription" TEXT, "description" TEXT, "htmlurl" TEXT, "rssurl" TEXT);
DROP TABLE IF EXISTS "comments";
CREATE TABLE "comments" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "comment_id" TEXT UNIQUE, "parent" TEXT, "user_id" TEXT, "datecreated" DATETIME, "status" TEXT, "content" TEXT, "link" TEXT, "post_id" TEXT, "post_title" TEXT, "author" TEXT, "author_url" TEXT, "author_email" TEXT, "author_ip" TEXT, "type" TEXT);
DROP TABLE IF EXISTS "custom_fields";
CREATE TABLE "custom_fields" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "custom_fields_id" TEXT UNIQUE, "key" TEXT, "value" TEXT);
DROP TABLE IF EXISTS "enclosure";
CREATE TABLE "enclosure" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "url" TEXT, "length" INTEGER, "type" TEXT);
DROP TABLE IF EXISTS "labels";
CREATE TABLE "labels" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "name" TEXT, "singular_name" TEXT, "search_items" TEXT, "popular_items" TEXT, "all_iterms" TEXT, "parent_item" TEXT, "parent_item_colon" TEXT, "edit_item" TEXT, "update_item" TEXT, "add_new_item" TEXT, "new_item_name" TEXT, "separate_items_with_commas" TEXT, "add_or_remove_items" TEXT, "choose_from_most_used" TEXT, "menu_name" TEXT, "name_admin_bar" TEXT, "view_item" TEXT);
DROP TABLE IF EXISTS "media";
CREATE TABLE "media" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "date_created_gmt" DATETIME, "parent" TEXT, "link" TEXT, "thumbnail" TEXT, "title" TEXT, "caption" TEXT, "description" TEXT, "metadata" TEXT, "attachment_id" TEXT);
DROP TABLE IF EXISTS "options";
CREATE TABLE "options" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "option_name" TEXT UNIQUE, "desc" TEXT, "value" TEXT, "readonly" BOOL);
DROP TABLE IF EXISTS "page";
CREATE TABLE "page" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "page_id" INTEGER UNIQUE, "title" TEXT, "datecreated" DATETIME, "date_created_gmt" DATETIME, "page_status" TEXT, "wp_slug" TEXT, "userid" INTEGER, "wp_author_id" TEXT, "wp_author_display" TEXT, "wp_password" TEXT, "excerpt" TEXT, "description" TEXT, "text_more" TEXT, "permalink" TEXT, "mt_allow_comments" INTEGER, "mt_allow_pings" INTEGER, "wp_page_parent_id" INTEGER, "wp_page_parent_title" TEXT, "wp_page_order" INTEGER, "wp_page_template" TEXT, "categories" TEXT, "custom_fields" TEXT);
DROP TABLE IF EXISTS "post";
CREATE TABLE "post" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "post_id" TEXT UNIQUE, "post_title" TEXT, "post_date" DATETIME, "post_date_gmt" DATETIME, "post_modified" DATETIME, "post_modified_gmt" DATETIME, "post_status" TEXT, "post_type" TEXT, "post_format" TEXT, "post_name" TEXT, "post_author" TEXT, "post_password" TEXT, "post_excerpt" TEXT, "post_content" TEXT, "post_parent" TEXT, "post_mime_type" TEXT, "link" TEXT, "guid" TEXT, "menu_order" INTEGER, "comment_status" TEXT, "ping_status" TEXT, "sticky" BOOL, "post_thumbnail" INTEGER, "term" TEXT, "custom_fields" TEXT, "enclosure" INTEGER);
DROP TABLE IF EXISTS "posttype";
CREATE TABLE "posttype" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "name" TEXT, "label" TEXT, "hierarchical" BOOL, "public" BOOL, "show_ui" BOOL, "builtin" BOOL, "has_archive" BOOL, "support" TEXT, "cap" TEXT, "map_meta_cap" BOOL, "menu_position" INTEGER, "menu_icon" TEXT, "show_in_menu" BOOL, "array_taxonomies" TEXT);
DROP TABLE IF EXISTS "tags";
CREATE TABLE "tags" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "tag_id" INTEGER UNIQUE, "name" TEXT, "slug" TEXT, "count" INTEGER, "html_url" TEXT, "rss_url" TEXT);
DROP TABLE IF EXISTS "taxonomy";
CREATE TABLE "taxonomy" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "name" TEXT UNIQUE, "label" TEXT, "hierarchical" BOOL, "public" BOOL, "show_ui" BOOL, "builtin" BOOL, "labels" TEXT, "cap" TEXT, "object_type" TEXT);
DROP TABLE IF EXISTS "term";
CREATE TABLE "term" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "term_id" TEXT UNIQUE, "name" TEXT, "slug" TEXT, "term_group" TEXT, "term_taxonomy_id" TEXT, "taxonomy" TEXT, "description" TEXT, "parent" TEXT, "count" INTEGER);
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "user_id" TEXT UNIQUE, "username" TEXT, "first_name" TEXT, "last_name" TEXT, "bio" TEXT, "email" TEXT, "nickname" TEXT, "nicename" TEXT, "url" TEXT, "display_name" TEXT, "registered" TEXT, "roles" TEXT);
DROP TABLE IF EXISTS "userblog";
CREATE TABLE "userblog" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "blogid" TEXT UNIQUE, "blogname" TEXT, "url" TEXT, "xmlrpc" TEXT, "isadmin" BOOL, "username" TEXT, "password" TEXT, "port" TEXT);
INSERT INTO "userblog" VALUES(1,'1','this is local site','wordpress.lc','/xmlrpc.php',1,'pndhainam','MTQzMDA3NWDR','80');
