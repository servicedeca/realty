<div class="col-xs-12 complex-filters zero-padding">

  <div class="col-xs-2 zero-padding complex-filters-select">
    <?php print render($form['field_apartament_home_tid']);?>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <select id="room" class="cf" multiple="multiple">
      <option value="1">Студия</option>
      <option value="2">1 кмн.</option>
      <option value="3">2 кмн.</option>
      <option value="4">3 кмн.</option>
    </select>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <select id="fsection" class="cf " multiple="multiple">
      <option value="1">1</option>
      <option value="2">1.1</option>
      <option value="3">2</option>
      <option value="4">2.2</option>
    </select>
  </div>

  <div class="col-xs-2 zero-padding complex-filters-select">
    <select id="ffloor" class="cf" multiple="multiple">
      <option value="1">1</option>
      <option value="2">1.1</option>
      <option value="3">2</option>
      <option value="4">2.2</option>
    </select>
  </div>

  <div class="col-xs-3 complex-filter-square zero-padding">
    <label class="complex-filter-square-lebel">от</label>
    <input  class="complex-filter-square-input" maxlength="3">
    <label class="complex-filter-square-lebel">до</label>
    <input  class="complex-filter-square-input" maxlength="3">
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