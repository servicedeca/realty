<div class="col-xs-12 complex-filters zero-padding">

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form['field_apartament_home_tid']);?>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form['field_number_rooms_value']);?>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form['field_section_value']);?>
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
  <a href="#" class="col-xs-1 complex-filter-clear-button zero-padding" title="Очистить все фильтры">
    <img src="images/clear.svg">
  </a>
  <?php print render($form['submit']);?>
</div>

<div class="element-hidden">
<?php drupal_render_children($form);?>
</div>