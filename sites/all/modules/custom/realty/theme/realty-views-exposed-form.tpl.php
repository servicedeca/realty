<div class="col-xs-12 complex-filters zero-padding">

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form_filter['address']);?>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form['field_number_rooms_value']);?>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form_filter['sections']);?>
  </div>

  <div class="col-xs-2 complex-filter-square zero-padding">
    <?php print render($form['field_apartment_floor_value']);?>
  </div>

  <div class="col-xs-3 complex-filter-square zero-padding">
    <?php print render($form['field_gross_area_value']['min'])?>
    <?php print render($form['field_gross_area_value']['max'])?>
    <label class="complex-filter-square-lebel">м<sup>2</sup></label>
  </div>
  <!-- <a href="#" class="col-xs-2  complex-filter-free-button zero-padding">
       Показать только свободные
   </a>
   -->
  <button type="button" class="col-xs-1 complex-filter-clear-button zero-padding" title="Очистить все фильтры">
    <?php print $button;?>
  </button>
</div>
<div class="dec_checkbox col-xs-6 col-xs-offset-3 zero-padding">
					<span>
						<input id="not-display-reserved" type="checkbox"  >
					</span>
  <label><?php print t('Do not display reserved');?></label>
</div>

<div class="element-hidden">
  <?php print render($form['sort_by']);?>
  <?php print render($form['sort_order']);?>
  <?php print render($form['field_apartament_home_tid']);?>
  <?php print render($form['field_section_value']);?>
  <?php print render($form['field_status_value']);?>
  <?php print render($form['submit']);?>
  <?php drupal_render_children($form);?>
</div>