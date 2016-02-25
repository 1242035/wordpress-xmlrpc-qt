/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __LABELS_H
#define __LABELS_H
#include "userblog.h"
class Labels
{
	private:
	   QString name;
       QString singular_name;
       QString search_items;
       QString popular_items;
       QString all_items;
       QString parent_item;
       QString parent_item_colon;
       QString edit_item;
       QString update_item;
       QString add_new_item;
       QString new_item_name;
       QString separate_items_with_commas;
       QString add_or_remove_items;
       QString choose_from_most_used;
       QString menu_name;
	   QString name_admin_bar;
	   QString view_item;

       
       QString tablename;
       int size;
       Database *Labels_db;
       public:
       Labels();
       ~Labels();
       
       //get
       QString Labels_get_name();
       QString Labels_get_menu_name();
	   QString Labels_get_name_admin_bar();
       QString Labels_get_singular_name();
       QString Labels_get_search_items();
       QString Labels_get_popular_items();
       QString Labels_get_all_items();
       QString Labels_get_parent_item();
       QString Labels_get_parent_item_colon();
       QString Labels_get_edit_item();
       QString Labels_get_update_item();
       QString Labels_get_add_new_item();
       QString Labels_get_new_item_name();
       QString Labels_get_separate_items_with_commas();
       QString Labels_get_add_or_remove_items();
       QString Labels_get_choose_from_most_used();
       QString Labels_get_view_item();
		//set
	   void Labels_set_name(QString name);
	   void Labels_set_menu_name(QString menu_name);
	   void Labels_set_name_admin_bar(QString name_admin_bar);
       void Labels_set_singular_name(QString singular_name);
       void Labels_set_search_items(QString search_items);
       void Labels_set_popular_items(QString popular_items);
       void Labels_set_all_items(QString all_items);
       void Labels_set_parent_item(QString parent_item);
       void Labels_set_parent_item_colon(QString parent_item_colon);
       void Labels_set_edit_item(QString edit_item);
       void Labels_set_update_item(QString update_item);
       void Labels_set_add_new_item(QString add_new_item);
       void Labels_set_new_item_name(QString new_item_name);
       void Labels_set_separate_items_with_commas(QString separate_items_with_commas);
       void Labels_set_add_or_remove_items(QString add_or_remove_items);
       void Labels_set_choose_from_most_used(QString choose_from_most_used);
       void Labels_set_view_item(QString view_item);
       
       //get size
       int Labels_get_size();
       void Labels_insert_db();
       int Labels_get_id();
};
#endif
