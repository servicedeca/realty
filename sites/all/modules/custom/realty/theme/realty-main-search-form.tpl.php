
<div class="col-xs-12" id="search-header">
  <ul>
    <li>
      <?php print $micro_logo ?>
    </li>
    <li class="search-title-city">
      <?php print t('Search for housing')?>
    </li>
    <li class="search-name-city">
      <a data-toggle="modal" data-target=".bs-example-modal-md">
        <?php print $city;?>
      </a>
    </li>
  </ul>
</div>
<div class="col-xs-12 search-top-line">
  <div class="col-xs-2 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Area')?>
      </label>
      <a data-toggle="modal" data-target=".modal-area">
        <input class="search-input search-input-area" readonly>
      </a>
    </div>
  </div>

  <div class="col-xs-2 search-top-line-item zero-padding item-left">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Developers')?>
      </label>
      <a data-toggle="modal" data-target=".modal-z">
        <input  class="search-input search-input-developer" readonly>
      </a>
    </div>
  </div>

  <div class="col-xs-1 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('RC')?>
      </label>
      <a data-toggle="modal" data-target=".modal-zk">
        <input  class="search-input search-input-complex mini-width" readonly>
      </a>
    </div>
  </div>

  <div class="col-xs-1 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Type')?>
      </label>
      <a data-toggle="modal" data-target=".modal-type">
        <input  class="search-input search-input-room mini-width" readonly>
      </a>
    </div>
  </div>

  <div class="col-xs-1 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('floor')?>
      </label>
      <?php print render($form['field_apartment_floor_value'])?>
    </div>
  </div>

  <div class="col-xs-2 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Masonry');?>
      </label>
      <?php print render($form['field_masonry_value'])?>
    </div>
  </div>

  <div class="col-xs-1 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Category');?>
      </label>
      <?php print render($form['field_category_value'])?>
    </div>
  </div>

  <div class="col-xs-2 search-top-line-item zero-padding">
    <div class="form-group text-center">
      <label class="hint">
        <?php print t('Deadline')?>
      </label>
      <div class="col-xs-7 zero-padding">
        <?php print render($form['field_home_deadline_quarter_value'])?>
      </div>
      <div class="col-xs-5 zero-padding padding-right">
        <?php print render($form['field_home_deadline_year_value'])?>
      </div>
    </div>
  </div>

</div>

<div class="col-xs-12 search-back-line zero-padding padding-left">
  <div class="col-xs-8 search-slider-block zero-padding">
    <div class="col-xs-4 search-slider-item">
      <label class="hint margin-bottom-35"><?php print t('Площадь, м').'<sup>2<sup>'?></label>
      <input type="hidden" class="sq ion-slider">
    </div>

    <div class="col-xs-4 search-slider-item">
      <label class="hint margin-bottom-35"><?php print t('Цена за м') . '<sup>2</sup>' . t(', тыс. руб')?></label>
      <input type="text" class="price ion-slider">
    </div>

    <div class="col-xs-4 search-slider-item">
      <label class="hint margin-bottom-35"><?php print t('Стоимость, млн. руб');?></label>
      <input type="text" class="coast ion-slider">
    </div>
  </div>

  <div class="col-xs-4 search-slider-block zero-padding">
    <div class="col-xs-12 search-last-item-top">
      <div class="col-xs-4">
        <div class="col-xs-2 col-xs-offset-2 box">
          <div class="form-group decor_checkbox">
            <label class="hint fix-hint">
              <?php print t('Parking');?>
            </label>
            <span>
              <input type="checkbox" id="parking">
            </span>
          </div>
        </div>
      </div>
      <div class="col-xs-4">
        <div class="form-group text-center">
          <label class="hint"><?php print t('Balcony')?></label>
          <select id="balkon" class="ss" multiple="multiple">
            <option id="balkon-0" value="0"><?php print t('balcony');?></option>
            <option id="balkon-1" value="1"><?php print t('loggia');?></option>
          </select>
        </div>
      </div>
      <div class="col-xs-4 metro-block">
        <div class="form-group text-center">
          <label class="hint">
            <?php print t('metro')?>
          </label>
          <a data-toggle="modal" data-target=".metro">
            <input  class="search-input search-input-metro" readonly>
          </a>
        </div>
      </div>
    </div>
    <div class="col-xs-12 search-last-item-bottom">
      <div class="col-xs-5">
      </div>
      <div class="col-xs-7 search-button-block">
        <?php print render($form['submit'])?>
      </div>
    </div>

  </div>
</div>
<div id="form-search-hidden">
  <?php print drupal_render_children($form); ?>
</div>
